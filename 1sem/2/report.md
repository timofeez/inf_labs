# Отчет по лабораторной работе № 2
## по курсу "Фундаментальная информатика"

Студент группы М8О-108Б-23 Григорьев Тимофей Андреевич

Работа выполнена 

Преподаватель: каф. 806 Севастьянов Виктор Сергеевич

1. **Тема**: Операции в терминале Linux
2. **Цель работы**: Изучение основных команд и операций в терминале Linux
3. **Задание**:
- Опробовать следующие команды:
    - who
    - pwd
    - ls
    - cd
    - cp
    - mv
    - rm
    - cat
    - ps
    - tail
    - head
    - grep
    - history
    - mkdir
    - rmdir
    - sudo
    - echo
    - ssh
    - scp
    - ssh-keygen
    - ssh-copy-id
- Использовать основные команды
- Сохранить листинг в файл
- Заархивировать
- Отправить на удаленную машину, там разархивировать
- Скачать разархивированный файл к себе на машину
4. **Идея, метод, алгоритм решения задачи**: 
Для выполнения данной лабораторной работы будем последовательно выполнять каждую из предложенных команд и операций. Для архивации файлов будем использовать команду `tar`. Для передачи файлов на удаленную машину и обратно - команду `scp`. Для работы с SSH-ключами - команды `ssh-keygen` и `ssh-copy-id`.
5. **Сценарий выполнения работы**: 
- Опробовать команды и операции, записывая результаты выполнения в файл `listing.md`
- Заархивировать файл `listing.md` с помощью команды `tar`
```bash
tar -czvf listing.tar.gz listing.md
```
- Отправить архив на удаленную машину с использованием `scp`
```bash
scp listing.tar.gz t_grigoriev@ip:~
```
- На удаленной машине разархивировать файл
```bash
tar -xzvf listing.tar.gz
```
- Скачать разархивированный файл обратно на локальную машину с использованием `scp`
```bash
scp t_grigoriev@ip:~/listing.md ~/"Рабочий стол"
```
6. **Протокол**: 
```bash
timofey@lpc:~$ who
timofey  tty2         2023-09-13 13:57 (tty2)
timofey  tty4         2023-09-16 16:35
timofey@lpc:~$ cd Загрузки/
timofey@lpc:~/Загрузки$ ls
Report-template.md
timofey@lpc:~/Загрузки$ pwd
/home/timofey/Загрузки
timofey@lpc:~/Загрузки$ cp Report-template.md ~/Рабочий\ стол/
timofey@lpc:~/Загрузки$ ls
Report-template.md
timofey@lpc:~/Загрузки$ cd ~/Рабочий\ стол/
timofey@lpc:~/Рабочий стол$ ls
Report-template.md
timofey@lpc:~/Рабочий стол$ mv Report-template.md ~
timofey@lpc:~/Рабочий стол$ cd
timofey@lpc:~$ ls
 code      pravoved             SOMETEST    Загрузки      Общедоступные
 history   Report-template.md   Видео       Изображения  'Рабочий стол'
 ORG       snap                 Документы   Музыка        Шаблоны
timofey@lpc:~$ rm Report-template.md 
timofey@lpc:~$ ls
 code      pravoved   Видео       Изображения    'Рабочий стол'
 history   snap       Документы   Музыка          Шаблоны
 ORG       SOMETEST   Загрузки    Общедоступные
timofey@lpc:~$ touch testfile
timofey@lpc:~$ echo "I can write in this file!" > testfile 
timofey@lpc:~$ ls
 code      pravoved   testfile    Загрузки      Общедоступные
 history   snap       Видео       Изображения  'Рабочий стол'
 ORG       SOMETEST   Документы   Музыка        Шаблоны
timofey@lpc:~$ cat testfile 
I can write in this file!
timofey@lpc:~$ rm testfile 
timofey@lpc:~$ ls
 code      pravoved   Видео       Изображения    'Рабочий стол'
 history   snap       Документы   Музыка          Шаблоны
 ORG       SOMETEST   Загрузки    Общедоступные
timofey@lpc:~$ ps
    PID TTY          TIME CMD
 155685 pts/0    00:00:00 bash
 155813 pts/0    00:00:00 ps
timofey@lpc:~$ cat /etc/passwd
root:x:0:0:root:/root:/bin/bash
daemon:x:1:1:daemon:/usr/sbin:/usr/sbin/nologin
bin:x:2:2:bin:/bin:/usr/sbin/nologin
sys:x:3:3:sys:/dev:/usr/sbin/nologin
sync:x:4:65534:sync:/bin:/bin/sync
games:x:5:60:games:/usr/games:/usr/sbin/nologin
man:x:6:12:man:/var/cache/man:/usr/sbin/nologin
lp:x:7:7:lp:/var/spool/lpd:/usr/sbin/nologin
mail:x:8:8:mail:/var/mail:/usr/sbin/nologin
news:x:9:9:news:/var/spool/news:/usr/sbin/nologin
uucp:x:10:10:uucp:/var/spool/uucp:/usr/sbin/nologin
proxy:x:13:13:proxy:/bin:/usr/sbin/nologin
www-data:x:33:33:www-data:/var/www:/usr/sbin/nologin
backup:x:34:34:backup:/var/backups:/usr/sbin/nologin
list:x:38:38:Mailing List Manager:/var/list:/usr/sbin/nologin
irc:x:39:39:ircd:/run/ircd:/usr/sbin/nologin
gnats:x:41:41:Gnats Bug-Reporting System (admin):/var/lib/gnats:/usr/sbin/nologin
nobody:x:65534:65534:nobody:/nonexistent:/usr/sbin/nologin
systemd-network:x:100:102:systemd Network Management,,,:/run/systemd:/usr/sbin/nologin
systemd-resolve:x:101:103:systemd Resolver,,,:/run/systemd:/usr/sbin/nologin
messagebus:x:102:105::/nonexistent:/usr/sbin/nologin
systemd-timesync:x:103:106:systemd Time Synchronization,,,:/run/systemd:/usr/sbin/nologin
syslog:x:104:111::/home/syslog:/usr/sbin/nologin
_apt:x:105:65534::/nonexistent:/usr/sbin/nologin
tss:x:106:112:TPM software stack,,,:/var/lib/tpm:/bin/false
uuidd:x:107:115::/run/uuidd:/usr/sbin/nologin
systemd-oom:x:108:116:systemd Userspace OOM Killer,,,:/run/systemd:/usr/sbin/nologin
tcpdump:x:109:117::/nonexistent:/usr/sbin/nologin
avahi-autoipd:x:110:119:Avahi autoip daemon,,,:/var/lib/avahi-autoipd:/usr/sbin/nologin
usbmux:x:111:46:usbmux daemon,,,:/var/lib/usbmux:/usr/sbin/nologin
dnsmasq:x:112:65534:dnsmasq,,,:/var/lib/misc:/usr/sbin/nologin
kernoops:x:113:65534:Kernel Oops Tracking Daemon,,,:/:/usr/sbin/nologin
avahi:x:114:121:Avahi mDNS daemon,,,:/run/avahi-daemon:/usr/sbin/nologin
cups-pk-helper:x:115:122:user for cups-pk-helper service,,,:/home/cups-pk-helper:/usr/sbin/nologin
rtkit:x:116:123:RealtimeKit,,,:/proc:/usr/sbin/nologin
whoopsie:x:117:124::/nonexistent:/bin/false
sssd:x:118:125:SSSD system user,,,:/var/lib/sss:/usr/sbin/nologin
speech-dispatcher:x:119:29:Speech Dispatcher,,,:/run/speech-dispatcher:/bin/false
fwupd-refresh:x:120:126:fwupd-refresh user,,,:/run/systemd:/usr/sbin/nologin
nm-openvpn:x:121:127:NetworkManager OpenVPN,,,:/var/lib/openvpn/chroot:/usr/sbin/nologin
saned:x:122:129::/var/lib/saned:/usr/sbin/nologin
colord:x:123:130:colord colour management daemon,,,:/var/lib/colord:/usr/sbin/nologin
geoclue:x:124:131::/var/lib/geoclue:/usr/sbin/nologin
pulse:x:125:132:PulseAudio daemon,,,:/run/pulse:/usr/sbin/nologin
gnome-initial-setup:x:126:65534::/run/gnome-initial-setup/:/bin/false
hplip:x:127:7:HPLIP system user,,,:/run/hplip:/bin/false
gdm:x:128:134:Gnome Display Manager:/var/lib/gdm3:/bin/false
timofey:x:1000:1000:timofey,,,:/home/timofey:/bin/bash
snapd-range-524288-root:x:524288:524288::/nonexistent:/usr/bin/false
snap_daemon:x:584788:584788::/nonexistent:/usr/bin/false
sshd:x:129:65534::/run/sshd:/usr/sbin/nologin
timofey@lpc:~$ cat /etc/passwd | grep timofey
timofey:x:1000:1000:timofey,,,:/home/timofey:/bin/bash
timofey@lpc:~$ history | grep ls
 1481  ls
 1483  ls
 1488  ls
 1490  ls
 1492  ls
 1494  ls
 1499  ls
 1502  ls
 1504  ls
 1507  ls
 1509  ls
 1512  ls
 1515  ls
 1520  history | grep ls
timofey@lpc:~$ tail -n 1 /etc/passwd
sshd:x:129:65534::/run/sshd:/usr/sbin/nologin
timofey@lpc:~$ service ssh status
○ ssh.service - OpenBSD Secure Shell server
     Loaded: loaded (/lib/systemd/system/ssh.service; enabled; vendor preset: e>
     Active: inactive (dead) since Mon 2023-09-18 17:43:43 MSK; 1 day 20h ago
       Docs: man:sshd(8)
             man:sshd_config(5)
   Main PID: 119727 (code=exited, status=0/SUCCESS)
        CPU: 32ms

сен 18 17:42:50 lpc systemd[1]: Starting OpenBSD Secure Shell server...
сен 18 17:42:51 lpc sshd[119727]: Server listening on 0.0.0.0 port 22.
сен 18 17:42:51 lpc sshd[119727]: Server listening on :: port 22.
сен 18 17:42:51 lpc systemd[1]: Started OpenBSD Secure Shell server.
сен 18 17:43:43 lpc sshd[119727]: Received signal 15; terminating.
сен 18 17:43:43 lpc systemd[1]: Stopping OpenBSD Secure Shell server...
сен 18 17:43:43 lpc systemd[1]: ssh.service: Deactivated successfully.
сен 18 17:43:43 lpc systemd[1]: Stopped OpenBSD Secure Shell server.
timofey@lpc:~$ head -n1 ~/Загрузки/Report-template.md
# Отчет по лабораторной работе № 2
timofey@lpc:~$ pwd
/home/timofey
timofey@lpc:~$ mkdir TESTDIR
timofey@lpc:~$ rmdir TESTDIR/
timofey@lpc:~$ sudo
usage: sudo -h | -K | -k | -V
usage: sudo -v [-ABknS] [-g group] [-h host] [-p prompt] [-u user]
usage: sudo -l [-ABknS] [-g group] [-h host] [-p prompt] [-U user] [-u user]
            [command]
usage: sudo [-ABbEHknPS] [-r role] [-t type] [-C num] [-D directory] [-g group]
            [-h host] [-p prompt] [-R directory] [-T timeout] [-u user]
            [VAR=value] [-i|-s] [<command>]
usage: sudo -e [-ABknS] [-r role] [-t type] [-C num] [-D directory] [-g group]
            [-h host] [-p prompt] [-R directory] [-T timeout] [-u user] file ...
timofey@lpc:~$ sudo su
[sudo] пароль для timofey: 
root@lpc:/home/timofey# whoami
root
root@lpc:/home/timofey# user
useradd  userdel  usermod  users    
root@lpc:/home/timofey# users
timofey timofey timofey
root@lpc:/home/timofey# su timofeez
su: user timofeez does not exist or the user entry does not contain all the required fields
root@lpc:/home/timofey# su timofey
timofey@lpc:~$ ssh-keygen
Generating public/private rsa key pair.
Enter file in which to save the key (/home/timofey/.ssh/id_rsa): 
Enter passphrase (empty for no passphrase): 
Enter same passphrase again: 
Your identification has been saved in /home/timofey/.ssh/id_rsa
Your public key has been saved in /home/timofey/.ssh/id_rsa.pub
The key fingerprint is:
SHA256:tw+62vpkxolr/V/BYpiinWnNozTvVucegO5x/rjFYMM timofey@lpc
The key's randomart image is:
+---[RSA 3072]----+
|                 |
|                 |
|                 |
|           = .   |
|        S = E o  |
|       = X +.*.. |
|      o.& O..o=  |
|      .O.*.B +.. |
|     .++*==.*+o  |
+----[SHA256]-----+
timofey@lpc:~$ ssh-copy-id t_grigoriev@185.5.249.140
/usr/bin/ssh-copy-id: INFO: Source of key(s) to be installed: "/home/timofey/.ssh/id_rsa.pub"
/usr/bin/ssh-copy-id: INFO: attempting to log in with the new key(s), to filter out any that are already installed
/usr/bin/ssh-copy-id: INFO: 1 key(s) remain to be installed -- if you are prompted now it is to install the new keys
t_grigoriev@185.5.249.140's password: 

Number of key(s) added: 1

Now try logging into the machine, with:   "ssh 't_grigoriev@185.5.249.140'"
and check to make sure that only the key(s) you wanted were added.

timofey@lpc:~$ cd Рабочий\ стол/
timofey@lpc:~/Рабочий стол$ ls
listing.md  report.md
timofey@lpc:~/Рабочий стол$ tar -czvf listing.tar.gz listing.md
listing.md
timofey@lpc:~/Рабочий стол$ ls
listing.md  listing.tar.gz  report.md
timofey@lpc:~/Рабочий стол$ rm listing.
listing.md      listing.tar.gz  
timofey@lpc:~/Рабочий стол$ rm listing.tar.gz
timofey@lpc:~/Рабочий стол$ tar -czvf listing.tar.gz listing.md
listing.md
timofey@lpc:~/Рабочий стол$ head -n1 listing.md
```bash
timofey@lpc:~/Рабочий стол$ ls
listing.md  listing.tar.gz  report.md
timofey@lpc:~/Рабочий стол$ scp listing.tar.gz t_grigoriev@185.5.249.140:~
listing.tar.gz                                100% 3179    68.3KB/s   00:00    
timofey@lpc:~/Рабочий стол$ ssh t_grigoriev@185.5.249.140
Welcome to Ubuntu 20.04.6 LTS (GNU/Linux 5.4.0-162-generic x86_64)

 * Documentation:  https://help.ubuntu.com
 * Management:     https://landscape.canonical.com
 * Support:        https://ubuntu.com/advantage
New release '22.04.3 LTS' available.
Run 'do-release-upgrade' to upgrade to it.

Last login: Mon Sep 18 18:38:09 2023 from 95.24.62.154
t_grigoriev@vds2476450:~$ ls
listing.tar.gz  remotefile
t_grigoriev@vds2476450:~$ rm remotefile 
t_grigoriev@vds2476450:~$ tar -xzvf listing.tar.gz 
listing.md
t_grigoriev@vds2476450:~$ ls
listing.md  listing.tar.gz
t_grigoriev@vds2476450:~$ logout
Connection to 185.5.249.140 closed.
timofey@lpc:~/Рабочий стол$ ls
listing.md  listing.tar.gz  report.md
timofey@lpc:~/Рабочий стол$ rm listing.md
timofey@lpc:~/Рабочий стол$ scp t_grigoriev@185.5.249.140:~ listing.md
scp: /home/t_grigoriev: not a regular file
timofey@lpc:~/Рабочий стол$ scp t_grigoriev@185.5.249.140:~/listing.md ~/"Рабочий стол"
listing.md                                    100% 9298   130.9KB/s   00:00    
timofey@lpc:~/Рабочий стол$ ls
listing.md  listing.tar.gz  report.md
```
7. **Замечания автора** отсутствуют
8. **Выводы**: В ходе выполнения лабораторной работы я познакомился с основными командами и операциями в терминале Linux. Эти знания могут быть полезными при работе с Linux-системами и автоматизации различных задач. Я также научился создавать и использовать SSH-ключи для безопасного доступа к удаленным серверам. Работа позволила мне лучше понять основы работы с командной строкой Linux и расширить свой навык взаимодействия с операционной системой через терминал.