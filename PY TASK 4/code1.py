from math import pi

def convert_angle(units=None, source_angle=None):
    print('*'*15,' Before Conversion ','*'*15)
    print('Units:',units)
    print('Source Angle:',source_angle)
    
    print('*'*15,' After Conversion ','*'*15)
    if units=="D":
        print(f'{source_angle} degrees is {(source_angle*pi)/180} radians')
    
    elif units=="R":
        print(f'{source_angle} radian is {source_angle*(180/pi)} degrees')
        
if __name__ == '__main__':
    unit=input('Enter Unit: ')
    angle=float(input('Enter Angle Value: '))
    
    convert_angle(unit,angle)
