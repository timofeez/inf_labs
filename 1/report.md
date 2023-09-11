# Отчет по лабораторной работе № 1
## по курсу "Фундаментальная информатика"

Студент группы М8О-108Б-23 Григорьев Тимофей Андреевич

Работа выполнена 

Преподаватель: каф. 806 Севастьянов Виктор Сергеевич

1. **Тема**: Знакомство с Git, Github
2. **Цель работы**: Ознакомиться с основами системы контроля версий Git и платформой для хостинга репозиториев Github
3. **Задание: 
 - завести репозиторий (**общий под все лабораторные работы с отдельной папкой под каждую лр!**)
- отчет с листингом в Markdown (листинг - ctrl+c -> ctrl+v из терминала с форматированием в markdown)
- создать отдельную ветку в репозитории под задание
- создать коммит с листингом и отчетом
- смержить ветку в мейн
4. **Идея, метод, алгоритм решения задачи**: 
- Завести репозиторий на Github
- Создать отдельную папку в репозитории под данную лабораторную работу.
- В папке создать файл отчета в формате Markdown.
- Создать отдельную ветку в репозитории для выполнения задания.
- В ветке создать коммит, включающий в себя листинг выполненных действий в терминале и отчет в Markdown.
- Смержить созданную ветку в ветку `main`
5. **Сценарий выполнения работы**:
- Создаем репозиторий на Github с названием "inf_labs"
- В репозитории создаем папку "1" для данной лабораторной работы
- Внутри папки "1" создаем файл отчета "report.md"
- Создаем отдельную ветку "lab1-branch" для выполнения задания
- Внутри ветки "lab1-branch" добавляем листинг выполненных команд в терминале в файл "report.md"
- Добавляем описание выполненной работы в файл "report.md".
- Создаем коммит с сообщением "Добавлен отчет по лабораторной работе №1"
- Смешиваем ветку "lab1-branch" с веткой "main" с помощью Pull Request
6. **Протокол**: 
```bash
timofey@lpc:~/coding> mkdir inf_labs 
timofey@lpc:~/coding> ls 
inf_labs  python 
timofey@lpc:~/coding> cd inf_labs 
timofey@lpc:~/coding/inf_labs> ls 
timofey@lpc:~/coding/inf_labs> git init 
hint: Using 'master' as the name for the initial branch. This default branch name 
hint: is subject to change. To configure the initial branch name to use in all 
hint: of your new repositories, which will suppress this warning, call: 
hint:  
hint:   git config --global init.defaultBranch <name> 
hint:  
hint: Names commonly chosen instead of 'master' are 'main', 'trunk' and 
hint: 'development'. The just-created branch can be renamed via this command: 
hint:  
hint:   git branch -m <name> 
Initialized empty Git repository in /home/timofey/coding/inf_labs/.git/ 
timofey@lpc:~/coding/inf_labs> ls 
timofey@lpc:~/coding/inf_labs> mkdir 1 
timofey@lpc:~/coding/inf_labs> ls 
1 
timofey@lpc:~/coding/inf_labs> touch 1/report.md 
timofey@lpc:~/coding/inf_labs> git remote add origin https://github.com/timofeez/inf_labs.git 
timofey@lpc:~/coding/inf_labs> git branch -M main 
timofey@lpc:~/coding/inf_labs> git push -u origin main 
error: src refspec main does not match any 
error: failed to push some refs to 'https://github.com/timofeez/inf_labs.git' 
timofey@lpc:~/coding/inf_labs> git add * 
timofey@lpc:~/coding/inf_labs> git status 
On branch main 

No commits yet 

Changes to be committed: 
 (use "git rm --cached <file>..." to unstage) 
       new file:   1/report.md 

timofey@lpc:~/coding/inf_labs> git checkout -b lab1-branch 
Switched to a new branch 'lab1-branch' 
timofey@lpc:~/coding/inf_labs> git status 
On branch lab1-branch 

No commits yet 

Changes to be committed: 
 (use "git rm --cached <file>..." to unstage) 
       new file:   1/report.md 

timofey@lpc:~/coding/inf_labs> vim 1/report.md

```
7. **Замечания автора** отсутствуют
8. **Выводы**: В результате выполнения лабораторной работы №1, я ознакомился с основами системы контроля версий Git и платформой Github. Эти навыки будут полезными в дальнейшем обучении и в профессиональной деятельности. Работа позволила понять, как эффективно организовывать и управлять проектами с использованием инструментов контроля версий и совместной разработки
