@echo off
chcp 65001 > nul

set /p NUM="문제 번호 입력: "
set /p TITLE="문제 제목 입력: "

set FOLDER=%NUM%

mkdir %FOLDER%
cd %FOLDER%

rem solve.cpp 생성
echo // > solve.cpp

rem README.md 생성
echo # Problem %NUM% - %TITLE% > README.md
echo. >> README.md
echo ## 📝 문제 설명 >> README.md
echo. >> README.md
echo (여기에 문제 설명을 작성하세요) >> README.md
echo. >> README.md
echo ## 🧠 배운 점 >> README.md
echo. >> README.md
echo - >> README.md
echo - >> README.md

echo ✅ 생성 완료!
pause
