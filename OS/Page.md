Page
==============

## 가상 메모리

> 메모리로서 실제 존재하지 않지만 사용자에게 있어서 메모리로서 역할을 하는 메모리

> 가상 메모리에 수용된 프로그램이 실행될 때에는 실제 메모리를 필요로 한다

> 프로세스들이 연속된 물리적 메모리 공간 처럼 여기게 만듦

> 필요한 부분만 메모리에 올림으로써 메인 메모리에 올라가는 프로세스의 크기를 줄인다

## 개발 배경

> 이전에는 실행되는 코드의 전부가 물리 메모리에 존재해야 했고, 따라서 메모리 용량보다 큰 프로그램은 실행 불가했다
> 또한, 여러 프로그램을 동시에 메모리에 올리면 용량의 한계와 페이지 교체 등의 성능 이슈가 발생
> 가끔 사용되는 코드가 차지하는 메모리들을 확인할 수 있다는 점에서 불필요하게 전체가 메모리에 있어야 하는게 아님을 알게됨
> 다중 프로그래밍을 실현하기 위해서는 많은프로세스들을 동시에 메모리에 올려야 한다
> 가상 메모리는 프로세스 전체가 메모리 내에 올리지 않더라도 실행 가능하도록 하는 기법
> 프로그램이 물리 메모리보다 커도 된다는 장점

## 가상 메모리가 하는 일

> 가상 메모리는 실제 물리 메모리의 개념과 사용자의 논리 메모리 개념을 분리한 것

> 작은 메모리를 가지고 얼마든지 큰 가상 주소 공간을 프로그래머에 제공

## 가상 주소 공간

> 한 프로세스가 메모리에 저장되는 논리적인 모습을 가상 메모리에 구현한 공간

> 프로세스가 요구하는 메모리 공간을 가상 메모리에서 제공함으로 현재 직접적으로 필요하지 않은 메모리 공간은 실제 물리 메모리에 올리지 않는 것으로 메모리 절약 가능

> ex) 프로그램이 실행되며 논리 메모리로 100kb가 요구되지만 
> 실행까지 필요한 메모리 공간(heap, stack, code, data)의 합이 40kb라면 
> 실제 물리 메모리에는 40kb만 올라가고 나머지 60kb만큼은 필요시 물리 메모리(보조기억장치 등)에 요구


> CPU가 생성하는 주소 = 논리 주소(logical address) = 가상 주소(virtual address)

> 메모리 상에서 유효한 주소(MAR, 메모리 주소 레지스터에 주어지는 주소) = 물리주소(physical address)

* Mapping

> 가상 메모리에 프로그램이 실행될 경우 어떤 과정을 통해 실제 메모리로 옮기는 것

> mapping 은 MMU(메모리 관리 장치, Memory Management Unit)라는 하드웨어에 의해 지원


## 요구 페이징(Demand Paging)

> 프로그램 실행 시작 시에 프로그램 전체를 디스크에서 물리 메모리에 적제하는 대신 
> 초기에 필요한 것들만 적재하는 전략

> 가상 메모리 시스템에서 많이 사용되며 가상 메모리는 대게 페이지로 관리

> 요구 페이징을 사용하는 가상메모리에서는 실행 과정에서 필요해질 때 페이지들이 적재

> 한 번도 실행되지 않은 페이지는 물리 메모리에 적재 x

> 프로세스 내의 개별 페이지들은 페이저(Pager)에 의해 관리

> 페이저는 프로세스 실행에 실제 필요한 페이지들만 메모리로 읽어와 사용되지 않을 페이지를 가져오는 시간낭비와 메모리 낭비를 감소


## 페이지 폴트(Page Fault)

> 프로그램이 자신의 주소공간에는 존재하지만 시스템의 RA에는 현재 없는 데이터나 코드에 접근을 시도했을 때 발생하는 현상

> 프로세스에 필요한 데이터만 적재하기 때문에 적재되지 않은 페이지를 요구하는 경우가 발생

* 과정

1. CPU가 원하는 주소를 MMU에 전송
2. MMU는 주소 변환 과정에서 페이지 테이블에 주소에 대한 항목이 없다고 표시
3. MMU는 CPU를 interrupt한 후 페이지 폴트 처리기라는 소프트웨어가 실행
4. 페이지 폴트 처리기가 원하는 페이지를 디스크 상 어디에 위치하는지 찾은 후 읽어옴

* 페이지 테이블(Page Table)

> 프로세스의 페이지 정보를 저장. 하나의 프로세스는 하나의 페이지 테이블을 소유

> 테이블은 색인(페이지 번호)와 내용(해당 페이지에 할당된 물리 메모리)으로 구성

* Effective Access Time

> Page fault Rate = p

> EAT = (1 - p) * memory access time + p * (page fault overhead + swap page out + swap page in + restart overhead)

![image](https://user-images.githubusercontent.com/94096054/160322442-5776d808-f236-4cc9-bccd-100ca209e163.png)

> swap out의 확률이 50%이므로 page fault 시 걸리는 시간은 (swap in + swap out * percent of swap out) -> paging time

> swap time인지 paging time인지 고려해서 계산해야 한다.



## TLB(Translation Look-aside Buffer, 변환 우선 참조 버퍼)


> page table의 일종의 cache 

> 페이지 테이블은 메인 메모리에 저장되기 때문에, 프로그램에 의한 모든 메모리 접근은 최소 두 번 필요하게 된다.

> 실제 주소를 얻기 위한 메모리 주소 접근 한번과 데이터를 얻기 위한 또 한번의 접근이 필요

* TLB Effective Access Time

> 계산시 Page fault는 고려하지 않는다

> TLB hit raio = P

> EAT = P * hit memory access time + (1 - p) * miss memory access time

> hit memory access time = TLB search + access memory time

> miss memory access time = TLB search + page aceess time + access memory time(same as page access time)


![image](https://user-images.githubusercontent.com/94096054/160324423-3a18fbcf-0bd3-46e7-adcf-ace83b11f9d1.png)























































