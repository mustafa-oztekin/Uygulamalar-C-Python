# HTML, HTML Web Sayfaları

import requests
from bs4 import BeautifulSoup

sayac = 0
for i in range(1,11):
    url = "https://stackoverflow.com/questions/tagged/python-requests?tab=newest&page="+str(i)+"&pagesize=50"
    response = requests.get(url)
    parser = BeautifulSoup(response.text, 'html.parser')
    questions = parser.find_all("div",{"class":"s-post-summary"})

    for q in questions:
        title = q.find("h3",{"class":"s-post-summary--content-title"})
        print(title.text.strip())
        content = q.find("div",{"class":"s-post-summary--content-excerpt"})
        print(content.text.strip())
        time =q.find("span",{"class":"relativetime"})
        print(time['title'])
        print("----------------------------")
        sayac += 1
        print("content count: ", str(sayac))
