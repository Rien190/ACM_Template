# ACM_Template
本仓库借鉴ply大佬的ACM Template,原仓库地址:https://github.com/palayutm/ply-template

本仓库仅个人学习使用.

本仓库也是只需更改`Rien-template.tex`即可.不同之处在于在封面加入了图片和个人邮箱,对于目录变成黑色,代码加入了代码行号和左边框.在完成编辑后使用

使用说明:
```
% \twocolumn  % 是否需要分栏显示 
\newpage %另起一页 
\section{String} %一级标题 
\subsection{KMP} %二级标题 
\inputminted[breaklines,linenos,frame=leftline]{c++}{string/kmp.cc} %导入模板文件 
```


```
xelatex -shell-escape Rien-template.tex
```
生成pdf

### Online

1. Download zip of this repository
2. Upload to [https://www.sharelatex.com]
3. Change Compiler to `XeLaTeX`
4. Compile

