from urllib2 import urlopen
from bs4 import BeautifulSoup
import re

url = 'http://uva.onlinejudge.org/external/4/485.html'
b = BeautifulSoup(urlopen(url).read())
print('%% %s' % url)
for tag in b.body:
    if tag.name == 'h1':
        print('\\section{%s}' % re.sub(r'<.*?>', '', str(tag)))
    elif tag.name == 'h2' or tag.name == 'h3':
        print('\\subsection{%s}' % re.sub(r'<.*?>', '', str(tag)))
    elif tag.name == 'pre':
        print('\\begin{verbatim}\n%s\n\end{verbatim}' % tag.string)
    else:
        print(re.sub(r'<.*?>', '', str(tag)))
