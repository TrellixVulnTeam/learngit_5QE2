##
##如果你经常阅读Python的官方文档，可以看到很多文档都有示例代码。比如re模块就带了很多示例代码：
##
## import re
## m = re.search('(?<=abc)def', 'abcdef')
## m.group(0)
##'def'
##可以把这些示例代码在Python的交互式环境下输入并执行，结果与文档中的示例代码显示的一致。
##
##这些代码与其他说明可以写在注释中，然后，由一些工具来自动生成文档。既然这些代码本身就可以粘贴出来直接运行，那么，可不可以自动执行写在注释中的这些代码呢？
##
##答案是肯定的。
##
##当我们编写注释时，如果写上这样的注释：

def abs(n):
    '''
    Function to get absolute value of number.

    Example:

    >>> abs(1)
    1
    >>> abs(-1)
    1
    >>> abs(0)
    0
    '''
    return n if n >= 0 else (-n)
    
##无疑更明确地告诉函数的调用者该函数的期望输入和输出。
##
##并且，Python内置的“文档测试”（doctest）模块可以直接提取注释中的代码并执行测试。
##
##doctest严格按照Python交互式命令行的输入和输出来判断测试结果是否正确。只有测试异常的时候，可以用...表示中间一大段烦人的输出。
##
##doctest非常有用，不但可以用来测试，还可以直接作为示例代码。
##通过某些文档生成工具，就可以自动把包含doctest的注释提取出来。
##用户看文档的时候，同时也看到了doctest。



class Dict(dict):
     '''
     Simple dict  but also support as d.x style

     >>> d1 = Dict()
     >>> d1['x'] = 100
     >>> d1.x
     100
     >>> d1.y = 200
     >>> d1['y']
     200
     >>> d2 = Dict(a=1,b='2',c='3')
     >>> d2.c
     '3'
     >>> d2['empty']
     Traceback (most recent call last):
     ...
     KeyError: 'empty'

     >>> d2.empty
     Traceback (most recent call last):
     ...
     AttributeError:  'object' has not attribute 'empty' 
     
     '''

     def __init__(self,**kw):
          super().__init__(**kw)


     def __setattr__(self,key,value):
          self[key] = value

     def __getattr__(self,key):
          try :
               return self[key]
          except KeyError:
               raise AttributeError(" 'object' has not attribute '%s' "%key)

if __name__ == '__main__':
     import doctest,re
     x = doctest.testmod()
     m = re.search('failed=0',str(x))
     print(m.group(0))
     
