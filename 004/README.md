# Problem 004 - 세자리 수를 곱해 만들 수 있는 가장 큰 대칭수

## 📝 문제 설명
앞에서부터 읽을 때나 뒤에서부터 읽을 때나 모양이 같은 수를 대칭수(palindrome)라고 부릅니다.  

두 자리 수를 곱해 만들 수 있는 대칭수 중 가장 큰 수는 9009 (= 91 × 99) 입니다.  

세 자리 수를 곱해 만들 수 있는 가장 큰 대칭수는 얼마입니까?

## 🧠 배운 점
- 곱셈 결과가 커질 수 있으므로 `long long` 사용 필요  
- 대칭수 판단은 문자열을 뒤집어 비교하면 쉬움
- 반복문을 큰 수부터 줄이면서 순회하면 빠르게 최대값 접근 가능
- 두번째 반복문에서 biggest보다 작은 값이 나오면 바로 break해 불필요한 계산 줄일 수 있음
