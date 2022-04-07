# importing required modules
import os
import sys
import lxml
import requests
from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
from bs4 import BeautifulSoup
from PyQt5.QtWebEngineWidgets import *
from serpapi import GoogleSearch  # API soulution


class MainWindow(QMainWindow):
    def __init__(self):
        super(MainWindow, self).__init__()
        self.browser = QWebEngineView()
        self.browser.setUrl(QUrl(
            'https://scholar.google.com/scholar?hl=en&as_sdt=0%2C5&q=school+of+life+sciences&btnG=&oq=school+of+life+sc'))
        self.setCentralWidget(self.browser)
        self.showMaximized()

        # navbar
        navbar = QToolBar()
        self.addToolBar(navbar)

        back_btn = QAction('Back', self)
        back_btn.triggered.connect(self.browser.back)
        navbar.addAction(back_btn)

        forward_btn = QAction('Forward', self)
        forward_btn.triggered.connect(self.browser.forward)
        navbar.addAction(forward_btn)

        reload_btn = QAction('Reload', self)
        reload_btn.triggered.connect(self.browser.reload)
        navbar.addAction(reload_btn)

        home_btn = QAction('Home', self)
        home_btn.triggered.connect(self.navigate_home)
        navbar.addAction(home_btn)

        self.url_bar = QLineEdit()
        self.url_bar.returnPressed.connect(self.navigate_to_url)
        navbar.addWidget(self.url_bar)

        self.browser.urlChanged.connect(self.update_url)

    def navigate_home(self):
        self.browser.setUrl(QUrl('https://scholar.google.com/'))

    def navigate_to_url(self):
        url = self.url_bar.text()
        self.browser.setUrl(QUrl(url))

    def update_url(self, q):
        self.url_bar.setText(q.toString())

    def search(self):
        #http proxy setup
        proxies = {
          'http': os.getenv('HTTP_PROXY')
        }

        params = {
            "api_key": os.getenv("API_KEY"),
            "engine": "google_scholar_profiles",
            "hl": "en",
            "mauthors": "SLC"
        }

        search = GoogleSearch(params)
        results = search.get_dict()Expl

        for result in results['profiles']:
            name = result['name']
        try:
            email = result['email']
        except:
            email = None
            author_id = result['author_id']
            affiliation = result['affiliations']
            cited_by = result['cited_by']
            interests = result['interests'][0]['title']
            interests_link = result['interests'][0]['link']

    visitedlinks = []
    queuelink = []

    def algo(self, visited, links, node):  # function for BFS links search
        visitedlinks.append(links)
        queuelink.append(links)
        while queuelink:
            m = queuelink.pop(0)
            for neighbour in links[m]:
                if neighbour not in visitedlins:
                    visited.linksappend(neighbour)
                    queuelink.append(neighbour)
#ENDOFCLASS


#driver code
app = QApplication(sys.argv)
QApplication.setApplicationName('GScholar')
window = MainWindow()
#executing app
app.exec_()
