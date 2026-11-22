// func tdcpRequest @ 00510460 size=1264

void * tdcpRequest(char *param_1)

{
  int __fd;
  int __fd_00;
  int __fd_01;
  size_t sVar1;
  int iVar2;
  int iVar3;
  __pid_t _Var4;
  int *piVar5;
  char *pcVar6;
  undefined4 uVar7;
  void *__s;
  int local_c0;
  int local_bc;
  int local_b8;
  int local_b4;
  int local_b0;
  sysinfo local_ac;
  sysinfo local_6c;
  
  pthread_mutex_lock((pthread_mutex_t *)&luciReqMutex);
  local_c0 = 0;
  sysinfo(&local_6c);
  gLastPassThrough = local_6c.uptime;
  if (param_1 == (char *)0x0) {
    __s = (void *)0x0;
    if (tdcp_luci_err_switch != 0) {
      pcVar6 = "[TDCP_LUCI_ERROR]%s()/%d requestJsonString is NULL!\n\n";
      uVar7 = 0xa5;
      goto LAB_00510558;
    }
  }
  else {
    sVar1 = strlen(param_1);
    if (sVar1 + 0x17 < 0x19018) {
      snprintf(&DAT_007689c0,0x19017,"%s=%s","requestJsonTdcpString",param_1);
      iVar2 = putenv(&DAT_007689c0);
      if (-1 < iVar2) {
        local_b4 = 0;
        local_b0 = 0;
        local_bc = 0;
        local_b8 = 0;
        iVar2 = pipe(&local_b4);
        if ((iVar2 < 0) ||
           (iVar3 = pipe(&local_bc), __fd_01 = local_b0, __fd_00 = local_b4, __fd = local_b8,
           iVar2 = local_bc, iVar3 < 0)) {
          if (0 < local_b4) {
            close(local_b4);
          }
          if (0 < local_b0) {
            close(local_b0);
          }
          if (0 < local_bc) {
            close(local_bc);
          }
          if (0 < local_b8) {
            close(local_b8);
          }
          if (tdcp_luci_debug_switch != 0) {
            printf("[TDCP_LUCI_DEBUG]%s()/%d 500, Internal Server Error, Failed to create pipe!\n\n"
                   ,"createPipe",0x85);
          }
          __s = (void *)0x0;
          if (tdcp_luci_err_switch == 0) goto LAB_005104f4;
          pcVar6 = "[TDCP_LUCI_ERROR]%s()/%d createPipe failed!\n\n";
          uVar7 = 0xb4;
        }
        else {
          __s = (void *)FUN_00408450(0x19000,0xb8);
          if (__s != (void *)0x0) {
            memset(__s,0,0x19000);
            pcVar6 = (char *)fork();
            if (pcVar6 == (char *)0xffffffff) {
              if (tdcp_luci_debug_switch != 0) {
                printf("[TDCP_LUCI_DEBUG]%s()/%d 500, Internal Server Error, Failed to fork child!\n\n"
                       ,"_tdcpRequest_lua",0xc6);
              }
              free(__s);
              close(__fd_00);
              close(__fd_01);
              close(iVar2);
              __s = (void *)0x0;
              close(__fd);
            }
            else {
              if (pcVar6 == (char *)0x0) {
                close(__fd_00);
                close(__fd);
                dup2(__fd_01,1);
                dup2(iVar2,0);
                execl(phys,phys,0);
                    /* WARNING: Subroutine does not return */
                exit(0);
              }
              close(__fd_01);
              close(iVar2);
              _Var4 = waitpid((__pid_t)pcVar6,&local_c0,0);
              iVar2 = 0x33;
              do {
                if (((-1 < _Var4) || (piVar5 = __errno_location(), *piVar5 != 4)) ||
                   (iVar2 = iVar2 + -1, iVar2 == 0)) goto LAB_005107f4;
                if (tdcp_luci_err_switch != 0) {
                  param_1 = pcVar6;
                  printf("[TDCP_LUCI_ERROR]%s()/%d waitpid again <%d> < %d > <%d>\n",
                         "_tdcpRequest_lua",0xe9,_Var4,pcVar6,4);
                }
                _Var4 = waitpid((__pid_t)pcVar6,&local_c0,0);
                sysinfo(&local_ac);
              } while (local_ac.uptime - local_6c.uptime < 5);
              if (tdcp_luci_err_switch != 0) {
                printf("[TDCP_LUCI_ERROR]%s()/%d passthrough had be action more than 3s,maybe timeout\n"
                       ,"_tdcpRequest_lua",0xef);
              }
LAB_005107f4:
              read(__fd_00,__s,0x19000);
              close(__fd_00);
              close(__fd);
              if ((_Var4 < 0) && (tdcp_luci_err_switch != 0)) {
                piVar5 = __errno_location();
                printf("[TDCP_LUCI_ERROR]%s()/%d waitpid again <%d> < %d > <%d>\n",
                       "_tdcpRequest_lua",0xfe,_Var4,pcVar6,*piVar5);
                param_1 = pcVar6;
              }
              if (tdcp_luci_debug_switch != 0) {
                printf("[TDCP_LUCI_DEBUG]%s()/%d DEBUG, buf: %s.\n\n","_tdcpRequest_lua",0x100,__s,
                       param_1);
              }
            }
            goto LAB_005104f8;
          }
          if (tdcp_luci_err_switch == 0) goto LAB_005104f8;
          pcVar6 = "[TDCP_LUCI_ERROR]%s()/%d malloc buf failed!\n\n";
          uVar7 = 0xbb;
        }
        goto LAB_00510558;
      }
    }
    else if (tdcp_luci_err_switch != 0) {
      printf("[TDCP_LUCI_ERROR]%s()/%d setenv failed, env buffer too small.\n","safeSetenv",0x55);
    }
    __s = (void *)0x0;
    if (tdcp_luci_err_switch != 0) {
      pcVar6 = "[TDCP_LUCI_ERROR]%s()/%d setenv failed!\n\n";
      uVar7 = 0xac;
LAB_00510558:
      printf(pcVar6,"_tdcpRequest_lua",uVar7);
      goto LAB_005104f8;
    }
  }
LAB_005104f4:
  __s = (void *)0x0;
LAB_005104f8:
  pthread_mutex_unlock((pthread_mutex_t *)&luciReqMutex);
  return __s;
}

