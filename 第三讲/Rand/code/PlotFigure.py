import pylab
import numpy

# y = [99854,  99899,  100022,  100177,  100055,  99729,  99602,  100653,  100269,  99740]
# x = range(10)
# y = [99455,  100060,  99524,  100103,  100150,  100243,  99781,  100185,  100031,  100400,  99897,  99699,  100472]
# x = range(13)

y = [100251,  100318,  100053,  100322,  99837,  99876,  99813,  99707,  99632,  100463, 99906, 100074,  100280,  99713,  99755]
x = range(15)

barWidth = 0.5

xVal = numpy.arange(len(x))
pylab.xticks(xVal+barWidth/2.0, x, rotation=45)

pylab.bar(x, y, width = barWidth, color = 'c')

pylab.xlabel('Random number')
pylab.ylabel('Frequency')
pylab.title('RandN(15) using RandN(7) : 1500000 times')
pylab.show()
