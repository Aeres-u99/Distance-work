#This program is intended for EDucational purpose and utilises ip-api to find the location of a given ip
#Please note that a max of 100 request can be made from a single ip in a go or else it will lead to ban from ip-api
#Do read their T&C for better utilisation for code
import json
import ipaddress as IP
from urllib.request import urlopen
print("------"*20)
print("\t"*2,"Program to find location and Isp details using IP","\t"*2)
print("Please Input the Ip address: ")
ip=input("> ")
ipadd = IP.ip_address(ip)
url="http://ip-api.com/json/"
url+=ip
Client=urlopen(url)
page = Client.read()
Client.close()
parsed_json = json.loads(page)
print("Country:[] ",parsed_json['country'])
print("Country Code:[] ",parsed_json['countryCode'])
print("RegionCode:[] ",parsed_json['region'])
print("RegionName:[] ",parsed_json['regionName'])
print("City:[] ",parsed_json['city'])
print("ZIP:[] ",parsed_json['zip'])
print("Lattitude:[] ",parsed_json['lat'])
print("Longitude:[] ",parsed_json['lon'])
print("TimeZone:[] ",parsed_json['timezone'],)
print("ISP:[] ",parsed_json['isp'])
print("OrganisationName:[] ",parsed_json['org'])
print("IP used For query:[] ",parsed_json['query'])
