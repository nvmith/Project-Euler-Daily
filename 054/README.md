# Problem 054 - 포커 게임에서 이긴 횟수 구하기 
 
## 📝 문제 설명  
포커라는 카드게임은 다섯 장으로 된 패의 높고 낮음에 따라 승부를 냅니다. (포커 규칙을 이미 아는 분이라면 규칙 설명 부분은 건너뛰셔도 좋습니다)  
  
카드 한 장은 아래와 같은 순서대로 값이 높아집니다.  
  
2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K, A  
  
다섯 장으로 이루어진 패의 계급(세칭 "족보")은, 낮은 것부터 높은 순서로 아래와 같습니다.  
  
High Card : 가장 높은 카드의 값으로 비교.  
One Pair : 한 쌍이 같은 카드.  
Two Pairs : 서로 다른 두 쌍이 같은 카드.  
Three of a Kind : 세 장이 같은 카드.  
Straight : 모든 카드가 연속된 숫자.  
Flush : 모든 카드의 무늬가 같음.  
Full House : 세 장이 같고, 또 한 쌍이 같음 (Three of a Kind + One Pair).  
Four of a Kind : 네 장이 같은 카드.  
Straight Flush : 모든 카드가 연속된 숫자이면서 무늬도 같음.  
Royal Flush : 10, J, Q, K, A가 무늬도 같음.  
  
두 사람의 패가 같은 종류의 계급이라면, 계급을 구성하는 카드 중 높은 쪽을 쥔 사람이 이깁니다. 예를 들면 8 원페어는 5 원페어를 이깁니다.  
계급을 이루는 카드 숫자까지 같으면 (예: 둘 다 Q 원페어), 다른 카드를 높은 순서대로 비교해서 승부를 정합니다.  
  
텍스트파일 [poker.txt](https://euler.synap.co.kr/files/poker.txt) 에는 두 선수가 벌인 1,000회의 승부가 저장되어 있습니다.  
한 줄에는 10장의 카드가 공백으로 분리되어 들어있는데, 앞의 다섯 장은 1번 선수 것이고 뒤의 다섯 장은 2번 선수의 패입니다. 잘못되거나 중복된 데이터는 없으며, 무승부도 없습니다.  

카드 숫자는 2, 3, ... , 9, T, J, Q, K, A 로 (숫자 10은 T로 표시),  
무늬는 C (Club - ♣), D (Diamond - ♦), H (Heart - ♥), S (Spade - ♠) 로 표시되어 있습니다.  
예를 들면 3C 3D 3S 9S 9D 의 경우 3 풀하우스가 됩니다.  
  
이 데이터를 분석하고, 1번 선수가 이긴 횟수를 구하세요.

## 🧠 배운 점
- 카드 5장을 벡터로 받고, 숫자/문자 분리해서 랭크/무늬 따로 저장
- 숫자별 개수 map으로 세어서 족보 판별 기준으로 사용
- `isFlush()`는 모든 무늬가 같은지, `isStraight()`는 연속된 숫자인지 확인
- A-2-3-4-5 예외 처리는 `vector<int>{2,3,4,5,14}`로 직접 비교
- `getRank()`는 족보를 정수로 변환 + 수의 높낮이 함께 반환
- 두 손패 비교는 족보 우선, 그다음 kicker 등 수의 높낮이 순차 비교
