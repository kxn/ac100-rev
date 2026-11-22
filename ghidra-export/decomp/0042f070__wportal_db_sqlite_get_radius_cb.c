// func _wportal_db_sqlite_get_radius_cb @ 0042f070 size=1000

undefined4
_wportal_db_sqlite_get_radius_cb
          (undefined4 param_1,int param_2,undefined4 *param_3,undefined4 *param_4)

{
  undefined1 *__s;
  int iVar1;
  size_t sVar2;
  undefined1 *__dest;
  size_t __n;
  undefined4 uVar3;
  char *__s1;
  char *pcVar4;
  int iVar5;
  undefined4 local_140;
  undefined4 local_13c;
  undefined4 local_138;
  undefined4 local_134;
  undefined4 local_130;
  undefined1 auStack_12c [260];
  
  uVar3 = 1;
  memset(auStack_12c,0,0xff);
  local_140 = 0;
  local_13c = 0;
  local_138 = 0;
  local_134 = 0;
  local_130 = 0;
  __s = (undefined1 *)FUN_00408450(0x134,0x3ce);
  if (__s != (undefined1 *)0x0) {
    memset(__s,0,0x134);
    for (iVar5 = 0; iVar5 < param_2; iVar5 = iVar5 + 1) {
      __s1 = (char *)*param_4;
      if (__s1 == (char *)0x0) goto LAB_0042f308;
      iVar1 = strcmp(__s1,"entry_id");
      if ((iVar1 == 0) && ((char *)*param_3 != (char *)0x0)) {
        iVar1 = atoi((char *)*param_3);
        *(int *)(__s + 0x108) = iVar1;
      }
      else {
        iVar1 = strcmp(__s1,"auth_port");
        if ((iVar1 == 0) && ((char *)*param_3 != (char *)0x0)) {
          iVar1 = atoi((char *)*param_3);
          *(int *)(__s + 0x10c) = iVar1;
        }
        else {
          iVar1 = strcmp(__s1,"account_port");
          if ((iVar1 == 0) && ((char *)*param_3 != (char *)0x0)) {
            iVar1 = atoi((char *)*param_3);
            *(int *)(__s + 0x110) = iVar1;
          }
          else {
            iVar1 = strcmp(__s1,"retry_count");
            if ((iVar1 == 0) && ((char *)*param_3 != (char *)0x0)) {
              iVar1 = atoi((char *)*param_3);
              *(int *)(__s + 0x114) = iVar1;
            }
            else {
              iVar1 = strcmp(__s1,"retry_interval");
              if ((iVar1 == 0) && ((char *)*param_3 != (char *)0x0)) {
                iVar1 = atoi((char *)*param_3);
                *(int *)(__s + 0x118) = iVar1;
              }
              else {
                iVar1 = strcmp(__s1,"radius_auth_type");
                if ((iVar1 == 0) && (pcVar4 = (char *)*param_3, pcVar4 != (char *)0x0)) {
                  iVar1 = strcmp(pcVar4,"pap");
                  uVar3 = 1;
                  if (iVar1 != 0) {
                    iVar1 = strcmp(pcVar4,"chap");
                    uVar3 = 2;
                    if (iVar1 != 0) {
                      iVar1 = strcmp(pcVar4,"mschap");
                      uVar3 = 3;
                      if (iVar1 != 0) {
                        iVar1 = strcmp(pcVar4,"mschapv2");
                        uVar3 = 4;
                        if (iVar1 != 0) {
                          uVar3 = 0xffffffff;
                        }
                        *(undefined4 *)(__s + 0x11c) = uVar3;
                        goto LAB_0042f12c;
                      }
                    }
                  }
                  *(undefined4 *)(__s + 0x11c) = uVar3;
                }
                else {
                  iVar1 = strcmp(__s1,"nas_identifier");
                  if ((iVar1 == 0) && (pcVar4 = (char *)*param_3, pcVar4 != (char *)0x0)) {
                    sVar2 = strlen(pcVar4);
                    __n = 100;
                    if (sVar2 < 0x65) {
                      __n = sVar2;
                    }
                    __dest = __s + 0x79;
                  }
                  else {
                    iVar1 = strcmp(__s1,"nas_ip");
                    if ((iVar1 == 0) && (pcVar4 = (char *)*param_3, pcVar4 != (char *)0x0)) {
                      sVar2 = strlen(pcVar4);
                      __n = 0x28;
                      if (sVar2 < 0x29) {
                        __n = sVar2;
                      }
                      __dest = __s + 0xde;
                    }
                    else {
                      iVar1 = strcmp(__s1,"share_key");
                      if ((iVar1 == 0) && (pcVar4 = (char *)*param_3, pcVar4 != (char *)0x0)) {
                        sVar2 = strlen(pcVar4);
                        __dest = __s;
                        __n = 0x78;
                        if (sVar2 < 0x79) {
                          __n = sVar2;
                        }
                      }
                      else {
                        iVar1 = strcmp(__s1,"server_addr");
                        if ((iVar1 != 0) || (pcVar4 = (char *)*param_3, pcVar4 == (char *)0x0))
                        goto LAB_0042f12c;
                        sVar2 = strlen(pcVar4);
                        __n = 0xff;
                        if (sVar2 < 0x100) {
                          __n = sVar2;
                        }
                        memset(auStack_12c,0,0xff);
                        __dest = auStack_12c;
                      }
                    }
                  }
                  memcpy(__dest,pcVar4,__n);
                }
              }
            }
          }
        }
      }
LAB_0042f12c:
      param_3 = param_3 + 1;
      param_4 = param_4 + 1;
    }
    iVar5 = wportal_db_rds_srv_add(__s);
    if (iVar5 == 0) {
      uVar3 = 0;
      iVar5 = FUN_0051a7a8(auStack_12c,&local_140);
      if (iVar5 == 0) {
        wportal_radius_server_table_add
                  (*(undefined4 *)(__s + 0x108),local_140,local_13c,local_138,local_134,local_130);
      }
    }
    else {
LAB_0042f308:
      FUN_00407df0(__s);
      uVar3 = 1;
    }
  }
  return uVar3;
}

