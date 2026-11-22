// func wportal_get_wechat_by_net @ 0043b7c4 size=1

undefined4 wportal_get_wechat_by_net(void)

{
  undefined4 uVar1;
  int __fd;
  FILE *__stream;
  char *pcVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  char acStack_3d0 [12];
  uint uStack_3c4;
  sockaddr sStack_3c0;
  char acStack_3b0 [64];
  char acStack_370 [256];
  int iStack_270;
  uint uStack_26c;
  
  __fd = socket(2,2,0);
  piVar3 = g_wechat_config;
  if (__fd != -1) {
    acStack_3d0[0] = '\0';
    acStack_3d0[1] = '\0';
    acStack_3d0[2] = '\0';
    acStack_3d0[3] = '\0';
    acStack_3d0[4] = '\0';
    acStack_3d0[5] = '\0';
    acStack_3d0[6] = '\0';
    acStack_3d0[7] = '\0';
    acStack_3d0[8] = '\0';
    acStack_3d0[9] = '\0';
    acStack_3d0[10] = '\0';
    acStack_3d0[0xb] = '\0';
    uStack_3c4 = 0;
    iVar5 = g_wechat_config[0x71];
    memset(acStack_370,0,0x100);
    snprintf(acStack_370,0x100,"dnsq %s",piVar3 + 0x31);
    memset(acStack_3b0,0,0x40);
    __stream = popen(acStack_370,"r");
    uVar1 = stderr;
    if (__stream == (FILE *)0x0) {
      piVar3 = __errno_location();
      pcVar2 = strerror(*piVar3);
      func_0x004071f0(uVar1,"execute command failed: %s",pcVar2);
    }
    else {
      pcVar2 = fgets(acStack_3b0,0x40,__stream);
      if (pcVar2 == (char *)0x0) {
        pclose(__stream);
      }
      else {
        strncpy(acStack_3d0,acStack_3b0,0xf);
        pcVar2 = acStack_3d0;
        iVar4 = 0;
        do {
          if ((9 < ((int)*pcVar2 - 0x30U & 0xff)) && (*pcVar2 != 0x2e)) {
            *pcVar2 = '\0';
          }
          iVar4 = iVar4 + 1;
          pcVar2 = pcVar2 + 1;
        } while (iVar4 != 0x10);
        uStack_3c4 = uStack_3c4 & 0xffffff00;
        pclose(__stream);
        uStack_3c4 = uStack_3c4 & 0xffffff00;
        iVar4 = func_0x00407a90(acStack_3d0,sStack_3c0.sa_data + 2);
        if (iVar4 == 1) {
          sStack_3c0.sa_data._0_2_ = (undefined2)iVar5;
          sStack_3c0.sa_family = 2;
          iVar5 = connect(__fd,&sStack_3c0,0x10);
          if ((-1 < iVar5) && (*g_wechat_config != 0)) {
            iVar5 = func_0x00407470();
            iVar4 = func_0x00407120(iVar5,__fd);
            if ((iVar4 == 0) || (iVar4 = func_0x00407970(iVar5), iVar4 < 1)) {
              func_0x00407030(iVar5);
            }
            else if (iVar5 != 0) {
              memset(&iStack_270,0,600);
              iStack_270 = iVar5;
              while (uStack_26c < 2) {
                iVar4 = _session_run(&iStack_270);
                if (iVar4 == 0) {
                  uStack_26c = uStack_26c + 1;
                }
                else {
                  uStack_26c = 3;
                }
              }
              iVar4 = func_0x004074e0(iVar5);
              if (iVar4 != 1) {
                func_0x004074e0(iVar5);
              }
              func_0x00407030(iVar5);
              if (0 < __fd) {
                close(__fd);
              }
              if (uStack_26c != 2) {
                return 0xffffffff;
              }
              return 0;
            }
          }
        }
      }
    }
    close(__fd);
  }
  return 0xffffffff;
}

