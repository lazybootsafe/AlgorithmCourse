# CTFHUB HTTP请求方式

+++

## 题意

~~~
HTTP Method is GET

Use CTF**B Method, I will give you flag.


Hint: If you got 「HTTP Method Not Allowed」 Error, you should request index.php.
~~~

题目重述：
使用 CTF**B 方式请求获得 flag

## 题解

+ 水平有限，百度出来了两种解决方法

  > ## 思路一
  >
  > 使用 JavaScript 创建`XMLHttpRequest()`对象，再用`open()`和`send()`方法发送`"CTFHUB"`请求方法。
  >
  > > 这种方法会遇到跨域访问限制的问题，目前对于跨域还是知识盲点，无法解决。

  	> ## 思路二
  	>
  	> + HTTP Method 是可以自定义的，并且区分大小写，直接用 CTFHUB 方法请求 index.php 即可拿到 flag.
  	>
  	> + 使用 Windows 自带的`cmd`命令行中的 **curl**命令。
  	>
  	> curl -v -X CTFHUB http://challenge-e42dc61cb067d561.sandbox.ctfhub.com:10080/index.php
  	>
  	> > 输入这个命令，按下回车，所有的服务器返回信息就会打印在下方。在返回的 html 源码中找到 ctfhub{……}即可。
  	> >
  	> > ![img](https://static.ctfhub.com/writeup/skill/web/preskill/http/basic_method/01.png?imageMogr2/auto-orient/thumbnail/1200x/blur/1x0/quality/75|watermark/1/image/aHR0cHM6Ly9zdGF0aWMuY3RmaHViLmNvbS93cml0ZXVwL2ltYWdlX21hc2sucG5n/dissolve/100/gravity/SouthEast/dx/10/dy/10|imageslim)

## 题后反思

+ 本题的考点是HTTP Method，他是可以自定义的，并且区分大小写；

+ **curl**命令

  > #### 1 介绍
  >
  > curl 命令在 Linux 操作系统中经常来测试网络和 url 的联通性，模拟正常的网络访问。除此之外，curl 还支持包括 HTTP、HTTPS、ftp 等众多协议，还支持 POST、cookies、认证、从指定偏移处下载部分文件等功能。
  >
  > #### 2 常用方法
  >
  > #### (1)**curl url**(获取网址的文本信息)
  >
  > ​	 curl www.baidu.com
  >
  > (2)**curl -i url**(获取文本的头部及文本信息)
  >
  > ​	curl -i www.baidu.com
  >
  > (3)**curl -x proxy url**(使用代理请求网页内容)
  >
  > ​	curl -x 0.0.0.0 www.baidu.com
  >
  > (4)**curl -v**(获取整个通信过程)
  >
  > ​	curl -v www.baidu.com
  >
  > (5)**curl -X url**(使用特定方法请求网页文本)
  >
  > //**参数X后面具体跟http的请求方法**
  >
  > ​	curl -X GET www.baidu.com
  >
  > > 在本题中就用到了 **(4),(5)** 两种命令。
  > >  要注意这里的`-X`是大写,而 **(3)** 中的 `-x`是小写。
  >
  > (6)**curl -I url**(仅返回头部信息)
  >
  > ​	curl -I www.baidu.com

