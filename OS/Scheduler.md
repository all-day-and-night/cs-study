Scheduler
==========

## Scheduler

> 프로세스를 스케줄링하기 위한 Queue

* Job Queue: 시스템에 들어올 때 진입하는 큐, 현재 시스템 내에 있는 모든 프로세스의 집합
* Ready Queue: 현재 메모리 내에 있으면서 CPU를 잡아 실행되기를 기다리는 프로세스의 집합
* Device Queue: 특정 입출력 장치를 대기하는 프로세스의 집합

## Process Scheduler

> 각각의 Queue에 프로세스들을 넣고 빼주는 스케줄러

### 장기 스케줄러(Long-term Scheduler, job scheduler)

> 메모리는 한정되어 있는데 많은 프로세스들이 한꺼번에 메모리에 올라올 경우, 대용량 메모리(일반적으로 디스크)에 임시로 저장

> 저장되어 있는 프로세스 중 어떤 프로세스에 메모리를 할당하여 Ready Queue로 보낼지 결정하는 역할

* 메모리와 디스크 사이의 스케줄링 담당
* 프로세스에 memory를 할당
* degree of Multiprogramming 제어(실행중인 프로세스의 제어)
* 프로세스의 상태(new -> ready)
* 시스템에서 새로운 프로세스를 생성하는 간격은 길기 때문에 실행 빈도수가 적다


### 단기 스케줄러(Short-term scheduler, CPU Scheduler)

* CPU와 메모리 사이의 스케줄링 담당
* Ready Queue에 존재하는 프로세스 중 어떤 프로세스를 running 시킬지 결정
* 어느 프로세스에게 CPU를 할당할 지
* 프로세스의 상태(ready -> running -> waiting -> ready)
* 단기 스케줄러는 실행 간격이 짧기 때문에 매우 빨라야 하며, 실행 빈도가 잦다.

### 중기 스케줄러(Medium-term scheduler, Swapper)

* 여유 공간 마련을 위해 프로세스를 통째로 메모리에서 디스크로 쫓아냄(Swapping)
* 프로세스에서 Memory를 deallocate(반납)
* degree of Multiprogramming 제dj
* 현 시스템에서 메모리에 너무 많은 프로그램이 동시에 올라가는 것을 조절하는 스케줄러
* 프로세스의 상태(ready -> suspended)


### CPU Scheduler

> CPU가 유휴상태가 될 때마다 Ready Queue에 있는 프로세스를 대상으로 실행될 프로세스를 선택

* 디스패치(Dispatch): 운영체제가 프로세스를 프로세서에 할당하는 것 // 프로세스의 상태가 ready -> running으로 바뀜

* 큐에 있는 레코드들은 일반적으로 프로세스들의 PCB

#### 스케줄링이 발생하는 상황

1. 프로세스가 실행 상태에서 대기 상태로 전환
2. 프로세스가 실행 상태에서 준비 완료 상태로 전환
3. 프로세스가 대기 상태에서 준비 완료 상태로 전환
4. 프로세스 종료

#### 비선점 스케줄링

* 프로세스가 할당된 뒤 CPU를 반납할 때 까지 점유
* 일괄 처리 방식에 적합
* 중요한 작업이 상대적으로 중요하지 않은 작업을 기다리는 경우 발생 가능

#### 선점 스케줄링

* 프로세스가 CPU를 할당받아 실행되고 있을 때, 우선 순위가 높은 다른 프로세스가 CPU를 강제로 빼앗아 올 수 있음
* 우선순위가 높은 프로세스를 빠르게 처리 가능
* 주로 빠른 응답시간을 요구하는 대화식 시분할 시스템에 사용

#### 평가 기준

* CPU 사용량(CPU Utilization)
* 처리량(Throughput): 단위 시간당 완료된 작업의 개수
* 소요시간(Turnaround Time): 작업이 요청되고 완료되기 까지 걸린 시간
* 수행시간(Burst Time): 쉬지않고 CPU를 할당했을 때 예상 처리 시간. 선점 등에 의해 소요시간이 더 길어질 수 있음
* 대기시간(Waiting Time): 대기 큐에서 기다린 시간
* 응답시간(Response Time): 요청이 도착된 시간부터 응답이 발생한 시점까지 걸린 시간

### 스케줄링 종류

#### FCFS(First Come First Served)

* 특징 

  + 먼저 온 고객을 먼저 서비스 해주는 방식, 즉 먼저 온 순서대로 처리
  + 비 선점형 스케줄링
  + 일단 CPU를 할당 받으면 CPU Burst가 완료될 때 까지 CPU를 반환하지 않음
  + 할당되었던 CPU가 반환될 때만 스케줄링이 이루어짐

* 문제점
  + 소요시간이 긴 프로세스가 먼저 도달하여 효율성을 낮추는 현상

#### SJF(Short Job First)

* 특징 

  + 다른 프로세스가 먼저 도착했어도 CPU Burst time이 짧은 프로세스에게 선 할당
  + CPU 버스트가 같다면 FCFS 적용
  + 주어진 프로세스 집합에 대해 최소 평균 대기시간을 가진다는 점에서 최적임
    - 하지만 다음 CPU 버스트의 길이를 파악하기 어려워 단기 CPU 스케줄링에서 구현 불가

  + 선점형, 비선점형 모두 가능
    - 프로세스가 실행되는 동안 새로운 프로세스가 더 짧은 CPU 버스트를 가질 때, 실행하는 프로세스를 선점한다면 선점형 프로세스

* 문제점

  + 기아 상태(Starvation)
  + 효율성을 추구하는게 가장 중요하지만 특정 프로세스가 지나치게 차별받으면 안되는 것
  + 극단적으로 CPU 사용이 짧은 job을 선호, 따라서 사용 시간이 긴 프로세스는 CPU할당을 못받는 상황이 생김



#### Priority Scheduler

* 특징
  + 우선순위가 가장 높은 프로세스에게 CPU를 할당
  + 우선순위가 같다면 FCFS
  + 선점형 스케줄링
    - 더 높은 우선순위의 프로세스가 도착하면 실행중인 프로세스를 멈추고 CPU 선점
  + 비선점형 스케줄링
    - 더 높은 우선순위의 프로세스가 도차갛면 Ready Queue의 head에 넣은다

* 문제점

  + 기아 상태
  + 무기한 봉쇄
    - 실행할 준비는 되어있지만 CPU를 사용하지 못하는 프로세스를 CPU가 무기한 대기하는 상태

* 해결책
  + 노화(Aging)
  + 기다리는 시간이 오래될수록 우선순위를 높임

#### Round Robin

* 특징 
  + 시분할 시스템을 위해 설계
  + 각 프로세스는 동일한 크기의 할당 시간(time quantum, 시간 할당량)을 갖는다
  + 할당 시간이 지나면 프로세스는 선점당하고(강제로 CPU 반납) Ready Queue의 맨뒤에서 다시 줄을 선다
  + Round Robin은 CPU 사용 시간이 랜덤한 프로세스들이 섞여있을 경우 효과적
  + 가능한 이유는 프로세스의 Context를 저장할 수 있기 때문(PCB)

* 장점
  + response time(반응시간)이 빨라진다
    - N 개의 프로세스가 Ready Queue에 있고 할당 시간이 Q(time quantum)인 경우 프로세스는 Q단위로 CPU시간의 1/N을 얻는다.
    - 즉 어떤 프로세스도 (N-1)Q time unit 이상 기다리지 않는다
  + 프로세스가 기다리는 시간이 CPU를 사용할 만큼 증가 -> 공정한 스케줄링

* 주의할 점
  + 설정한 time quantum이 너무 커지면 FCFS와 같아진다
  + 설정한 time quantum이 너무 작아지면 오히려 Context Switching이 너무 빈번하게 일어나 overhead가 발생함
  + 적정 time quantum을 설정해야 함















































