// func apupd_ptn_infor_get @ 004099f4 size=772

/* WARNING: Removing unreachable block (ram,0x00409a94) */

undefined4 apupd_ptn_infor_get(int param_1,char *param_2,int *param_3,undefined4 *param_4)

{
  int iVar1;
  size_t sVar2;
  int iVar3;
  size_t sVar4;
  char *pcVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined4 local_230 [128];
  int local_30;
  
  memset(local_230,0,0x200);
  if ((((param_1 == 0) || (param_2 == (char *)0x0)) || (param_3 == (int *)0x0)) ||
     (param_4 == (undefined4 *)0x0)) {
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    pcVar5 = "[APUPD_ERROR]%32s() %05d: inputs error.\r\n";
    uVar6 = 0x499;
  }
  else {
    *param_3 = -1;
    *param_4 = 0xffffffff;
    iVar1 = apupd_str_to_args(param_1,&DAT_007120e8,local_230,0x80);
    if (iVar1 != -1) {
      puVar7 = local_230;
      local_30 = iVar1 / 6;
      iVar1 = 0;
      do {
        while( true ) {
          if (local_30 <= iVar1) {
            if (g_apupd_error == 0) {
              return 0xffffffff;
            }
            iVar1 = is_target_debug_ap();
            if (iVar1 == 0) {
              return 0xffffffff;
            }
            printf("[APUPD_ERROR]%32s() %05d: cannot get ptn for %s\r\n","apupd_ptn_infor_get",0x4c2
                   ,param_2);
            return 0xffffffff;
          }
          pcVar5 = (char *)*puVar7;
          iVar8 = iVar1 * 6;
          sVar2 = strlen(pcVar5);
          if ((sVar2 != 8) || (iVar3 = strncmp("fwup-ptn",pcVar5,8), iVar3 != 0)) break;
          sVar2 = strlen(param_2);
          pcVar5 = (char *)puVar7[1];
          sVar4 = strlen(pcVar5);
          if ((sVar2 == sVar4) && (iVar3 = strncmp(param_2,pcVar5,sVar2), iVar3 == 0)) {
            pcVar5 = (char *)puVar7[2];
            sVar2 = strlen(pcVar5);
            if ((sVar2 == 4) && (iVar3 = strncmp("base",pcVar5,4), iVar3 == 0)) {
              iVar1 = apupd_str_to_ul(local_230[iVar8 + 3],0,0x10);
              *param_3 = iVar1 + 0x101c;
              uVar6 = apupd_str_to_ul(local_230[iVar8 + 5],0,0x10);
              *param_4 = uVar6;
              return 0;
            }
          }
LAB_00409aec:
          puVar7 = puVar7 + 6;
          iVar1 = iVar1 + 1;
        }
        if (g_apupd_error == 0) goto LAB_00409aec;
        iVar3 = is_target_debug_ap();
        if (iVar3 == 0) goto LAB_00409aec;
        printf("[APUPD_ERROR]%32s() %05d: argv[%d](%s) is not %s.\r\n","apupd_ptn_infor_get",0x4b1,
               iVar8,*puVar7,"fwup-ptn");
        puVar7 = puVar7 + 6;
        iVar1 = iVar1 + 1;
      } while( true );
    }
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    pcVar5 = "[APUPD_ERROR]%32s() %05d: parse the table of partition failed\r\n";
    uVar6 = 0x4a3;
  }
  printf(pcVar5,"apupd_ptn_infor_get",uVar6);
  return 0xffffffff;
}

