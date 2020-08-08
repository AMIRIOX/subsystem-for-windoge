# Linux Subsystem for Windoge OS

[简体中文](README-zh.md) | [English](README.md)

## Introductions

This is a subsystem for Windoge OS.
Windoge OS is just a joke, but this windoge system is different from other windoge systems.
We will build a Wiki for you to use as soon as possible.

## How to Use

### for Linux

``` bash
$ cd windoge10-release-0.1.0/
$ sudo mount -o loop ./windoge10-release-0.1.0.iso /mnt/windoge
$ cd /mnt/windoge
$ ls
$ ./wdg
```

### for Windows 

#### First, Install WSL

``` powershell
> Enable-WindowsOptionalFeature -Online -FeatureName Microsoft-Windows-Subsystem-Linux
```

then, download WSL System image(*.appx) or download in Microsoft Store.

![install in MS Store](https://s1.ax1x.com/2020/08/07/aR6iM8.png)

![download from wiki.ubuntu.com](https://s1.ax1x.com/2020/08/07/aR6wQK.png)

![download from docs.microsoft.com](https://s1.ax1x.com/2020/08/09/aoZs6x.png)

> If you download the mirror from wiki.ubuntu.com or docs.microsoft.com (assuming Ubuntu.appx), you need:

``` powershell
> New-Item D:\Ubuntu -ItemType Directory
> Set-Location D:\Ubuntu
> Rename-Item .\Ubuntu.appx Ubuntu.zip
> Expand-Archive .\Ubuntu.zip -Verbose
> cd Ubuntu
> .\ubuntu1804.exe
```

It should now show:

``` 
Installing, this may take a few minutes...
Please create a default UNIX user account. The username does not need to match your Windows username.
For more information visit: https://aka.ms/wslusers
Enter new UNIX username: <Enter your Linux username here>
Enter new UNIX password: <Password, note that the password is not echoed, you will not see it if you enter it>
Retype new UNIX password: <Repeat the password>
passwd: password updated successfully
Installation successful!
```

#### Second, Install ISO Image

* Enter WSL:

_ubuntu1804.exe_

* Double-click `windoge10-release-0.1.0.iso`
Observe which drive letter the image is mounted to (assuming F:)

* mount iso!

``` bash
$ sudo mount -t drvfs F: /mnt/windoge
$ cd /mnt/windoge
$ ./wdg
```

> You can eject the iso arbitrarily, but you need to re-enter the mount command to load the next time you enter.
> For convenience, you can use alias. Let's take zsh as an example (bash uses .bash_rc)

``` bash
$ vim ~/.zshrc
```

Add a row: 
_alias imt="sudo mount -t drvfs F: /mnt/windoge"_
Next time you use it, you can use `imt` directly.

### for macOS

**Not currently supported**
