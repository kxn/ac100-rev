// func _wportal_send_http_request_get @ 004355a0 size=300

undefined4 _wportal_send_http_request_get(undefined4 param_1)

{
  char *__s;
  int __fd;
  int iVar1;
  undefined4 uVar2;
  size_t sVar3;
  ssize_t sVar4;
  sockaddr local_28;
  
  __s = (char *)FUN_00408450(0x200,0x6c);
  if (__s != (char *)0x0) {
    memset(__s,0,0x200);
    __fd = socket(2,2,6);
    if (-1 < __fd) {
      local_28.sa_data[6] = '\0';
      local_28.sa_data[7] = '\0';
      local_28.sa_data[8] = '\0';
      local_28.sa_data[9] = '\0';
      local_28.sa_data[0] = '\0';
      local_28.sa_data[1] = '\0';
      local_28.sa_family = 2;
      local_28.sa_data[10] = '\0';
      local_28.sa_data[0xb] = '\0';
      local_28.sa_data[0xc] = '\0';
      local_28.sa_data[0xd] = '\0';
      local_28.sa_data[2] = '\x7f';
      local_28.sa_data[3] = '\0';
      local_28.sa_data[4] = '\0';
      local_28.sa_data[5] = '\x01';
      local_28.sa_data._0_2_ = wportal_get_portal_port();
      iVar1 = connect(__fd,&local_28,0x10);
      if (iVar1 != -1) {
        uVar2 = wportal_get_portal_port();
        sprintf(__s,
                "GET %s  HTTP/1.1\r\nHost: 127.0.0.1:%d\r\nConnection: Keep-Alive\r\nCache-Control: max-age=0\r\n\r\nAccept: text/html, image/jpeg, image/png, vedio/x-mng, text/*, image/*, */*\r\nAccept-Lauguage: zh-cn\r\nAccept-Encoding: x-gzip, x-deflate, gzip, deflat\r\nAccept-charset: utf-8, utf-8; q=0.5, *; q=0.5\r\nUser-Agent: Mozilla/5.0 (Windows NT 5.1) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/38.0.2125.101 Safari/537.36 OPR/25.0.1614.50\r\n\r\n"
                ,param_1,uVar2);
        sVar3 = strlen(__s);
        sVar4 = send(__fd,__s,sVar3 + 1,0);
        if (sVar4 != -1) {
          FUN_00407df0(__s);
          close(__fd);
          return 0;
        }
      }
      close(__fd);
    }
    FUN_00407df0(__s);
  }
  return 0xffffffff;
}

