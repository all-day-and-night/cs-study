Java
=====

> C언어에 객체 지향적 기능을 추가하여 만든 C++과 달리, 처음부터 객체지향 언어로 개발된 프로그래밍 언어

> 자바 가상머신(JVM)을 사용하여 운영체제와 "독립"적으로 동작 가능


### 자바의 특징

* 장점 :

  + 운영체제와 독립적으로 실행
  + 불필요한 기능을 과감히 제거하여 다른 언어에 비해 배우기 쉬움
  + 자동 메모리 관리 등을 지원하여 안정성이 높음
  + 연산자 오버로딩을 금지하고 제네릭을 도입하여 코드의 가독성을 높임

* 단점 :
  
  + 실행을 위해 JVM을 거쳐야 하기 때문에, 다른 언어에 비해 실행 속도가 느림
  + 예외 처리가 잘 되어 있지만, 일일이 개발자가 처리를 지정해줘야 함
  + 다른 언어에 비해 작성해야 하는 코드의 길이가 긴 편


### JRE JDK

* JRE : Java Runtime Environment

> 자바 가상 머신, 자바 클래스 라이브러리, 자바 명령 및 기타 인프라를 포함한, 컴파일된 Java 프로그램을 실행하는데 필요한 패키지

* JDK : Java Development Kit

> Java를 사용하기 위해 필요한 모든 기능을 갖춘 Java 용 SDK(Software Development Kit)

> JDK는 프로그램을 생성하고 컴파일 할 수 있다.



> JDK는 JRE를 포함하고 있으며 프로그램을 실행만 한다면 JRE만 설치해도 무관하다.

> 하지만 Java로 프로그래밍을 할 경우 JDK가 필요하다





### Java 프로그램의 실행 과정 

![image](https://user-images.githubusercontent.com/94096054/151130312-d04abb44-c1cd-48cf-aef7-4f44f0442624.png)


* Java Compiler 

> 자바 컴파일러는 자바로 작성한 소스 코드를 자바 가상 머신이 이해할 수 있는 자바 바이트 코드로 변환


* Java Byte Code

> 자바 가상 머신이 이해할 수 있는 언어로 변환된 자바 소스 코드

> JVM만 있다면 어떤 운영체제에서라도 실행할 수 있음

* Java Virtual Machine

> 자바 가상 머신이란 자바 바이트 코드를 실행하기 위한 가상의 기계

> 자바로 작성된 모든 프로그램은 자바 가상 머신에서만 실행될 수 있으므로, 자바 프로그램을 실행하기 위해서는 JVM이 필요

![image](https://user-images.githubusercontent.com/94096054/151282568-634631ff-c785-4f64-9ec1-303d651b62f9.png)


* JVM의 구성

1. 자바 인터프리터

> 자바 컴파일러에 의해 변환된 자바 바이트 코드를 읽고 해석하는 역할

2. 클래스 로더

> 자바는 동적으로 클래스를 읽어오므로, 프로그램이 실행 중인 런타임에서야 모든 코드가 자바 가상 머신과 연결된다.

> 동적으로 클래스를 로딩해주는 역할을 하는 것이 클래스 로더

4. JIT 컴파일러

> 프로그램이 실행중인 런타임에 실제 기계어로 변환해주는 컴파일러를 의미

> 동적 번역이라고 불리는 이 기법은 프로그램의 실행 속도를 향상 시키기 위해 개발

> 자바 컴파일러가 생성한 자바 바이트 코드를 런타임에 바로 기계어로 변환하는데 사용

6. 가비지 컬렉터

> 더는 참조되지 않는 인스턴스나 메모리를 자동으로 회수

> 메모리를 관리하지 않아도 GC가 메모리를 관리해줌으로 쉽게 프로그래밍 할 수 있음


* Java Runtime Data Area

![image](https://user-images.githubusercontent.com/94096054/160544759-1a75c1e4-665c-4dea-b034-8d424c50e926.png)

> JVM이 프로그램을 수행하기 위해 OS로부터 할당받는 메모리 영역

> 다음과 같이 5개의 영역으로 구분된다.

1. PC register

  * Java의 PC register는 CPU 내의 register와 유사하지만 다르게 작동한다.

  * (stack base vs Register base)

  * 현재 수행 중인 JVM Instruction의 주소를 가진다.

2. JVM stack

  * Thead의 Method가 호출될 때 수행 정보(Method 호출 주소, 매개 변수, 지역 변수, 연산 스택)가 Frame이라는 단위로 JVM Stack에 저장

3. Native method stack

  * Java 외의 언어로 작성된 네이티브 코드들을 위한 stack

4. Heap

  * 모든 스레드가 공유

  * 인스턴스와 배열이 동적으로 생성되는 공간

  * Garbage Collector가 작동하는 영역

  * 객체를 제거하기 위해 별도의 코드 작성이 불필요

  * 동기화 문제 야기

5. Method Area

  * Class Loader가 적재한 클래스(또는 인터페이스)에 대한 메타데이터 정보가 저장

  * 이 영역에 등록된 class만이 Heap에서 메모리 생성 가능

  * 논리적으로 Heap에 포함
  * 

> PC register, JVM stack, Native method stack은 각각의 스레드에 독립적으로 할당받는 메모리

> Heap, Method Area는 모든 Thread가 공유



* 람다 표현식

> 메소드를 하나의 식으로 표현한 것

> 식별자 없이 실행할 수 있는 함수 표현식

* Ex)

```
new Thread(() -> {
  System.out.println("this is lambda expression");
}).start();
```

* Stream API

> 자바에서는 많은 양의 데이터를 저장하기 위해서 배열이나 컬렉션을 사용하는데 

> 저장된 데이터에 접근하기 위해서는 반복문이나 반복자(iterator)를 사용하여 코드를 작성한다. 

> Stream API를 사용할 경우 데이터를 추상화하여 다루므로, 다양한 방식으로 저장된 데이터를 읽고 쓰기 위한 공통된 방법을 제공한다.

> 지연(Lazy) 연산을 통해 성능을 최적화 가능

```
String[] arr = new String[]{"하나", "둘", "셋", "넷"};

Stream<String> stream1 = Arrays.stream(arr);
stream1.forEach(e -> System.out.print(e + " ");

```

## 자바 면접 예상 질문 리스트

### 변수란? 

> 변수란 데이터를 담는 공간

> 한 번에 하나의 데이터만 저장 가능

----------
