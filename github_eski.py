import requests

class GitHub:
    def __init__(self):
        self.api_url = "https://api.github.com"
        self.token = ""

    def getUser(self, username):
        response = requests.get(self.api_url + "/users/" + username)
        return response.json()
    
    def getRepos(self, username):
        response = requests.get(self.api_url + "/users/" + username + "/repos")
        return response.json()
    
    def createRepository(self, name):
        headers = {
            "Authorization": f"token {self.token}"
        }
        data = {
            "name": name,
            "description": "This is your first repo!",
            "homepage": "https://github.com",
            "private": False,
            "is_template": True
        }

        response = requests.post(f"{self.api_url}/user/repos", json=data, headers=headers)
        return response.json()
    
github = GitHub()

while True:
    secim = input("1- Find User\n2- Get Repositories\n3- Create Repository\n4- Exit\nSeçim: ")

    if secim == "4":
        break
    else:
        if secim == "1":
            username = input("username: ")
            result = github.getUser(username)
            print(f"name: {result['name']} public repos: {result['public_repos']} followers: {result['followers']}")

        elif secim == "2":
            username = input("username: ")
            result = github.getRepos(username)
            for repository in result:
                print(repository['name'])

        elif secim == "3":
            name = input("repository name: ")
            result = github.createRepository(name)
            print(result)

        else:
            print("yanlış seçim...")