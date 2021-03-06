#우리 서비스에 맞는 프레임워크는 무엇이란 말인가.

시크릿차트에 쓰일 프레임워크에 대해 정말 끝을 보려는 문서다.<br>
근 일주일동안 기술스택에 관해서 논해왔지만 결국 목적은 아래와 같다.
>결국 우리 서비스에 맞는 프레임워크는 무엇인가?


##Author

**시크릿차트 개발팀 Jade(염승우)**<br>
질문사항 있으시면 언제든지  연락주세요.

##웹 프레임워크의 선택
![](/Users/Jade/Desktop/Screen\ Shot\ 2016-07-13\ at\ 5.34.34\ PM.png)

보통 프레임워크를 크게 구분할 때 **풀스택 프레임워크**와 **마이크로 프레임워크** 크게 두가지로 나눌 수 있다.

**풀스택 프레임워크**는 주로 한 프레임워크에서 모든 분야를 다 섬렵하는 프레임워크이다. 이 말은, 통신에서 데이터베이스까지, 그리고 URL 처리에서 웹페이지 템플릿 작업까지의 모든것을 망라한 기능을 갖추고 있다는 것이다.

유명한 풀스택 프레임워크는 `Django`, `Laravel`, `CodeIgniter` 등이 있다.

**마이크로 프레임워크**는 경량 프레임워크라고도 많이 알려져있다. 작고 가벼움을 강조하며 필수요소만 제공한다는 특징을 가지고 있으며, 여러 라이브러리와 플러그인이 함꼐 사용되야 하는 경우가 많아서 학습커브가 높기때문에, 숙련자들에게 추천된다.

유명한 마이크로 프레임워크는 `Lumen`, `koa.js`, `Flask`, `Hapi.js` 등이 있다.

###그럼 각각의 프레임워크는 언제 사용할까?

다음은 **[프레임워크 종류 문의 (돌고)](http://dolgo.net/%ED%94%84%EB%A0%88%EC%9E%84%EC%9B%8C%ED%81%AC/questions/57)** 질문글의 채택글이다.

>소규모 프로젝트에서 신속하게 어떤 기능을 필요로 하는 경우 Micro Framework의 사용이 최선의 선택일 수 있습니다. Full Stack Framework만큼 우리가 필요로하는 모든 기능을 갖추고 있지는 않지만 필요에 따라 기능을 추가할 수 있는 유연성과 Full Stack Framework에 비해 빠르기 때문입니다. 대규모 프로젝트이고 많은 요구사항이 있다면 Full Stack Framework을 사용하면 됩니다.

확실히 맞는 말이다. 프로젝트 규모에 따라서 풀스택 프레임워크를 쓰느냐, 마이크로 프레임워크를 쓰느냐가 결정될 수도있다. 하지만 기술 스택 구조측면에서 백단에 REST API로 마이크로 프레임워크를 사용하고, 앞단에 프론트엔드 프레임워크를 사용하는게 조금 더 구조적이라고 판단되어 사용되는 경우도 있다.

##풀 스택 프레임워크

풀 스택 프레임워크는 위에서 언급됬듯이 모든것을 갖추고 있는 프레임워크다. 데이터베이스 I/O를 통해 REST API를 제공해주고, 모델을 통해 웹 페이지 단에서도 직접적으로 DB접근과 IO가 가능하는 등 모든 것을 한번에 개발할 수 있다.

###장점

 - 프레임워크 내에서 거의 모든 작업을 처리할 수 있다.
	 - 마이크로 프레임워크에 없는 것들이 다 있다.
	 - 모든 내장 모듈이나 라이브러리들이 강력해서 서드파티에 의존할 필요가 없다.
 - 규모가 큰 프로젝트에 적합하다.
	 - 위에서 언급했었듯, 모든걸 다 갖추고 있어 따로 신경쓸게 없다.

###단점

 - 소규모 프로젝트에 맞지 않다.
	 - 자잘한 프로젝트라면 풀스택보다는 마이크로 프레임워크만을 써도 충분하다.

###주변 활용 사례
 - 기존의 **Django VS Laravel** 의 활용사례 참고.

##마이크로 프레임워크 + 프론트엔드 프레임워크

마이크로 프레임워크는 보통 REST API 애플리케이션을 따로 두고 프론트엔드 프레임워크에서 API를 요청받아 뿌려주는 식이다. 이렇게 설계하면 각종 클라이언트(웹, 모바일 애플리케이션)에서는 REST API 하나에 모든 처리를 부담할 수 있다.

###주변 활용 사례
 - **CCN (Clean City Networks)**
	 - Node.js + Express.js + Angular.js
	 - 데이터 업데이트가 많은 동적인 페이지에 효율적이라서 사용한다고 한다.


###장점
 - 언급했듯 데이터 업데이트가 많은 동적인 페이지에 정말 효율적이다.
 - 모든 처리를 REST API에서 부담하게 하므로, 별도로 웹을위한 모델을 작성하거나 할 필요가 없다.
 
###단점
 - 정적인 페이지엔 부담만 줘서 쓸모가 없다.
	- 정적인 페이지인데, Angular.js 같은 프론트엔드 프레임워크를 쓴다고 해서 좋은점은 없다.
 - 두 프레임워크를 따로따로 다뤄야 하기 때문에  유지보수 할 때 조금 불편하다는 점이 있다.
 
##결론

프로젝트가 크거나 대부분 정적인 페이지로 이루어져 있다면 **풀스택 프레임워크**를 고려해보는게 좋을 것 같다.<br>
반대로 프로젝트 규모가 작거나 대부분이 동적인 페이지로 이루어져 있다면 **마이크로 프레임워크**와 **프론트 프레임워크**를 함께 사용하여 개발하면 좋을 듯 하다.

시크릿차트는 아직 기획이 정확히 나오지 않아서 확실하게 말할 순 없지만, 데이터의 업데이트가 많은 동적인 페이지로 이루어질것도 아니거니와 소규모 프로젝트도 아니므로 **풀스택 프레임워크**로 모든 작업을 처리하는것이 맞는 것 같다.

