# [CauArchive](https://github.com/CauArchive/sprout_22)

## 사용하기전 해야할 것

[따라하기](https://codesyun.tistory.com/89)

## 정기적으로 컴파일 파일 삭제하는 방법

```code
1. find ./ -type d -name "*.dSYM" -exec rm -rf {} \;
2. find ./ACMICPC -type f ! -iname "*.*" -exec rm -rf {} \;
```
