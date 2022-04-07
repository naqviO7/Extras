import pandas as pd
import wikipedia
import matplotlib.pyplot as plt
from wordcloud import WordCloud
from sklearn.cluster import KMeans
from sklearn.feature_extraction.text import TfidfVectorizer

articles = ['Data Science', 'Artificial intelligence', 'Machine Learning', 'European Central Bank',
            'Bank', 'Financial technology', 'International Monetary Fund', 'Basketball', 'Swimming', 'Tennis']
wiki_lst = []
title = []

for article in articles:
   print("loading content: ", article)
   wiki_lst.append(wikipedia.page(article).content)
   title.append(article)

print("examine content")

vectorizer = TfidfVectorizer(stop_words={'english'})
X = vectorizer.fit_transform(wiki_lst)

Sum_of_squared_distances = []
K = range(2, 10)

for k in K:
   km = KMeans(n_clusters=k, max_iter=200, n_init=10)
   km = km.fit(X)
   Sum_of_squared_distances.append(km.inertia_)

plt.plot(K, Sum_of_squared_distances, 'bx-')
plt.xlabel('k')
plt.ylabel('Sum_of_squared_distances')
plt.title('Elbow Method For Optimal k')
plt.show()

true_k = 6
model = KMeans(n_clusters=true_k, init='k-means++', max_iter=200, n_init=10)
model.fit(X)
labels = model.labels_
wiki_cl = pd.DataFrame(list(zip(title, labels)), columns=['title', 'cluster'])
print(wiki_cl.sort_values(by=['cluster']))

result = {'cluster': labels, 'wiki': wiki_lst}
result = pd.DataFrame(result)

for k in range(0, true_k):
   s = result[result.cluster == k]
   text = s['wiki'].str.cat(sep=' ')
   text = text.lower()
   text = ' '.join([word for word in text.split()])
   wordcloud = WordCloud(max_font_size=50, max_words=100,
                         background_color="white").generate(text)
   print('Cluster: {}'.format(k))
   print('Titles')
   titles = wiki_cl[wiki_cl.cluster == k]['title']
   print(titles.to_string(index=False))
   plt.figure()
   plt.imshow(wordcloud, interpolation="bilinear")
   plt.axis("off")
   plt.show()
