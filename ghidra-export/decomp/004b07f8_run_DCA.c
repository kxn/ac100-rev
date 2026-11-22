// func run_DCA @ 004b07f8 size=624

undefined4
run_DCA(void *param_1,size_t param_2,undefined4 param_3,int param_4,int param_5,int param_6)

{
  char cVar1;
  char *__s;
  void *__dest;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  void *pvVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  short sVar9;
  undefined4 local_40 [2];
  int local_38;
  size_t local_34;
  int local_30;
  
  if (rrm_algo_switch != '\0') {
    printf("[RRM_PKT]%s()/%d ap_num = %d, supported_channel_num = %d \n","run_DCA",0xe2,param_2,
           param_4);
  }
  __s = (char *)FUN_00408450(param_2,0xe8);
  uVar3 = 0xffffffff;
  if (__s != (char *)0x0) {
    memset(__s,0,param_2);
    local_34 = param_2 * 0x2a;
    __dest = (void *)FUN_00408450(local_34,0xf0);
    local_38 = 0;
    if (__dest == (void *)0x0) {
      FUN_00407df0(__s);
    }
    else {
      local_30 = param_6 - param_5;
      for (; local_38 < (int)param_2; local_38 = local_38 + 1) {
        sVar9 = -1;
        uVar6 = 0xffffffff;
        pcVar4 = __s;
        pvVar5 = param_1;
        iVar7 = param_5;
        for (uVar8 = 0; (int)uVar8 < (int)param_2; uVar8 = uVar8 + 1) {
          if (*pcVar4 == '\0') {
            iVar2 = FUN_00407fe0(iVar7);
            if (iVar2 == 0) {
              iVar2 = FUN_00407fe0(local_30 + iVar7);
              if (iVar2 == 0) {
                *pcVar4 = '\x01';
                *(undefined1 *)((int)pvVar5 + 3) = 0xff;
                *(undefined1 *)((int)pvVar5 + 4) = 0xff;
                *(undefined1 *)((int)pvVar5 + 5) = 0xff;
                goto LAB_004b08dc;
              }
              cVar1 = *pcVar4;
            }
            else {
              cVar1 = *pcVar4;
            }
            if ((cVar1 == '\0') && (sVar9 < *(short *)((int)pvVar5 + 10))) {
              uVar6 = uVar8;
              sVar9 = *(short *)((int)pvVar5 + 10);
            }
          }
LAB_004b08dc:
          pcVar4 = pcVar4 + 1;
          pvVar5 = (void *)((int)pvVar5 + 0x2a);
          iVar7 = iVar7 + 0xc;
        }
        if (uVar6 == 0xffffffff) break;
        __s[uVar6] = '\x01';
        uVar8 = 0;
        memcpy(__dest,param_1,local_34);
        local_40[0] = 0;
        do {
          if (param_4 <= (int)uVar8) break;
          iVar7 = dfs(0,uVar6 & 0xffff,1,0,0,param_4,uVar8 & 0xff,param_1,param_2,param_5,param_6,0,
                      local_40,__dest);
          uVar8 = uVar8 + 1;
        } while (iVar7 == 0);
      }
      uVar3 = 0;
      FUN_00407df0(__s);
      FUN_00407df0(__dest);
    }
  }
  return uVar3;
}

