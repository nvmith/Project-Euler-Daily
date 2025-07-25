# Problem 044 - 합과 차도 모두 오각수인 두 오각수 차의 최솟값은? 
 
## 📝 문제 설명  
오각수는 Pn = n (3n − 1)/2 라는 공식으로 구할 수 있고, 처음 10개의 오각수는 다음과 같습니다.  

1, 5, 12, 22, 35, 51, 70, 92, 117, 145, ...  

위에서 P4 + P7 = 22 + 70 = 92 = P8이 됨을 볼 수 있습니다. 하지만 두 값의 차인 70 − 22 = 48 은 오각수가 아닙니다.  

합과 차 모두 오각수인 두 오각수 Pj, Pk 에 대해서, 그 차이 D = | Pk − Pj | 는 가장 작을 때 얼마입니까?

## 🧠 배운 점  
- 오각수 공식 `Pn = n(3n-1)/2`을 이용해 10000개 정도 생성  
- 오각수 여부는 `unordered_set`을 이용해 구분 
- 차이를 `min(diff)`로 갱신하며 가장 작은 경우를 추적  
