웹 브라우저에서 URL을 칠 때 일어나는 일
=======================================

1. 브라우저 주소창에 URL을 입력
2. 브라우저가 해당 URL의 IP 주소를 찾기 위해 웹 브라우저 캐시에서 DNS 기록을 확인한다.
3. 만약 URL이 캐시에 없다면, ISP의 DNS 서버가 DNS 쿼리로 URL을 호스팅하는 서버의 IP 주소를 찾는다.
4. 브라우저가 해당 서버와 TCP 연결을 시작한다.
5. 브라우저가 웹서버에 HTTP 요청을 보낸다.
6. 서버가 요청을 처리하고 HTTP 응답을 보낸다.
7. 브라우저가 HTML 컨텐츠를 보여준다.

### ISP (Internet Service Provider)

> 개인이나 기업체에게 인터넷 접속 서비스, 웹사이트 구축 및 웹호스팅 서비스 등을 제공하는 회사를 말한다. 

> 대표적으로 한국에서는 KT, SK브로드밴드, LG U+ 등이 있다. 

### DNS (Domain Name System)

> 웹 사이트의 IP 주소와 도메인 주소를 연결해주는 시스템

> 인터넷의 모든 URL에는 고유한 IP 주소가 할당되어 있다.

> terminal에서 nslookup "url"을 치면 해당 url에 해당된 IP 주소를 얻을 수 있다.
