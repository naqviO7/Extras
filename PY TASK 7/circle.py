import math

class Circle:
	def __init__(self,radius=1):
		"""Circle initializer"""
		self.radius=radius

		if radius < 0:
			print('Radius cannot be negative!')

	def __str__(self):
		return f'Circle({self.radius})'

	def __repr__(self):
		rep='Circle('+str(self.radius)+')'
		return rep

	def property(function):
		def wrapper(*args,**kwargs):
			val=function(*args,**kwargs)
			print('Property')
			return val
		return wrapper

	def setter(function):
		def wrapper(*args,**kwargs):
			val=function(*args,**kwargs)
			print('Value is Stored.')
			return val 
		return wrapper

	@property
	def area(self):
		"""Calculate and return the area of the Circle"""
		return f'Area of Circle: {math.pi * self.radius ** 2}'

	@property
	def diameter(self):
		"""Calculate and return the diameter of the Circle"""
		return f'Diameter of Circle: {self.radius * 2}'

	@setter
	def dimeter(self,diameter):
		"""Set the diameter"""
		_radius = diameter / 2
		return f'_Radius: {_radius}'


if __name__ == '__main__':
	c=Circle(3)
	print(c)
	print(c.area())
	print(c.diameter())
	print(c.dimeter(4))
