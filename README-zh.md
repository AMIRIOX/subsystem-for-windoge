# 用于Windoge OS的Linux子系统

[English](README.md) | [简体中文](README-zh.md)

## 简介

这是Windoge OS的子系统。
Windoge OS只是一个梗，但是此windoge系统与其他windoge系统不同。
我们将构建一个Wiki，供您尽快使用。

## 如何使用

### 对于 Linux

``` bash
$ cd windoge10-release-0.1.0 /
$ sudo mount -o loop ./windoge10-release-0.1.0.iso / mnt / windoge
$ cd / mnt / windoge
$ ls
$ ./wdg
```

### 对于 Windows

#### 首先，安装WSL

``` powershell
> Enable-WindowsOptionalFeature -Online -FeatureName Microsoft-Windows-Subsystem-Linux
```

然后，下载WSL系统映像(* .appx)或在Microsoft Store中下载。

![在MS Store中安装](https://s1.ax1x.com/2020/08/07/aR6iM8.png)

![从wiki.ubuntu.com下载](https://s1.ax1x.com/2020/08/07/aR6wQK.png)

![从docs.microsoft.com下载](https://s1.ax1x.com/2020/08/09/aoZs6x.png)

> 如果从wiki.ubuntu.com或docs.microsoft.com(假设Ubuntu.appx)下载镜像，则需要：

``` powershell
> New-Item D:\Ubuntu -ItemType Directory
> Set-Location D:\Ubuntu
> Rename-Item .\Ubuntu.appx Ubuntu.zip
> Expand-Archive .\Ubuntu.zip -Verbose
> cd Ubuntu
> .\ubuntu1804.exe
```

现在应该显示：

``` 
Installing, this may take a few minutes...
Please create a default UNIX user account. The username does not need to match your Windows username.
For more information visit: https://aka.ms/wslusers
Enter new UNIX username: <这里输入你的Linux用户名>
Enter new UNIX password: <密码, 注意密码不回显, 你输入是看不到的>
Retype new UNIX password: <重复密码>
passwd: password updated successfully
Installation successful!
```

#### 第二，安装ISO映像

* 进入WSL：

_ubuntu1804.exe_

* 双击 `windoge10-release-0.1.0.iso`
观察将映像安装到哪个驱动器盘符(假设F:)

* 安装ISO!

``` bash
$ sudo mount -t drvfs F:/mnt/windoge
$ cd /mnt/windoge
$ ./wdg
```

> 您可以任意弹出iso，但是需要在下次输入时重新输入mount命令来加载。
> 为方便起见，您可以使用别名。让我们以zsh为例(bash使用.bash_rc)

``` bash
$ vim ~/.zshrc
```

添加一行：
_alias imt =" sudo mount -t drvfs F:/mnt/windoge"_
下次使用它时，可以直接使用 `imt` 。

###适用于macOS

**目前不支持**
