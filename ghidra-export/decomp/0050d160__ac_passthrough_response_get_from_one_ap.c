// func _ac_passthrough_response_get_from_one_ap @ 0050d160 size=660

undefined4
_ac_passthrough_response_get_from_one_ap
          (int *param_1,FILE *param_2,undefined4 param_3,int *param_4,int *param_5)

{
  int iVar1;
  size_t sVar2;
  int iVar3;
  void *__ptr;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  char acStack_a8 [128];
  
  memset(acStack_a8,0,0x80);
  uVar4 = 0;
  if ((param_5 != (int *)0x0) && (param_4 != (int *)0x0)) {
    iVar7 = *param_5;
    iVar6 = *param_4;
    iVar1 = get_reponse_by_id_from_list(param_1,param_3);
    uVar5 = 0xffffffff;
    uVar4 = uVar5;
    if (((iVar1 != 0) &&
        ((*(int *)(iVar1 + 0x18) != 0 &&
         (uVar4 = 0xffffffff, iVar6 + *(int *)(iVar1 + 0x10) < 0x73ff)))) &&
       ((iVar7 < 1 || (sVar2 = fwrite(&DAT_00678b90,1,1,param_2), uVar4 = uVar5, sVar2 == 1)))) {
      memset(acStack_a8,0,0x80);
      snprintf(acStack_a8,0x80,
               "{\"sub_device_mac\":\"%02x-%02x-%02x-%02x-%02x-%02x\", \"report_info\":",
               (uint)*(byte *)(param_1 + 4),(uint)*(byte *)((int)param_1 + 0x11),
               (uint)*(byte *)((int)param_1 + 0x12),(uint)*(byte *)((int)param_1 + 0x13),
               (uint)*(byte *)(param_1 + 5),(uint)*(byte *)((int)param_1 + 0x15));
      sVar2 = strlen(acStack_a8);
      sVar2 = fwrite(acStack_a8,sVar2,1,param_2);
      if (sVar2 == 1) {
        if (ac_passthrough_debug_switch == '\0') {
          __ptr = *(void **)(iVar1 + 0x18);
        }
        else {
          printf("[AC_PASSTHROUGH_DEBUG]%s()/%d write len:%d \r\ncon:%s to file !\n",
                 "_ac_passthrough_response_get_from_one_ap",0x4a4,*(undefined4 *)(iVar1 + 0x10),
                 *(undefined4 *)(iVar1 + 0x18));
          __ptr = *(void **)(iVar1 + 0x18);
        }
        sVar2 = fwrite(__ptr,*(size_t *)(iVar1 + 0x10),1,param_2);
        if (sVar2 == 1) {
          sVar2 = fwrite("}",1,1,param_2);
          if (sVar2 != 1) {
            return 0xffffffff;
          }
          iVar3 = *(int *)(iVar1 + 0x10);
          FUN_00408500(iVar1);
          if (*(int *)(iVar1 + 0x18) != 0) {
            FUN_00407df0();
            *(undefined4 *)(iVar1 + 0x18) = 0;
          }
          FUN_00407df0(iVar1);
          *param_1 = *param_1 + -1;
          *param_5 = iVar7 + 1;
          *param_4 = iVar6 + iVar3;
          return 0;
        }
        if (ac_passthrough_err_switch == '\0') {
          return 0xffffffff;
        }
        uVar4 = 0x4a7;
      }
      else {
        if (ac_passthrough_err_switch == '\0') {
          return 0xffffffff;
        }
        uVar4 = 0x4a1;
      }
      printf("[AC_PASSTHROUGH_ERROR]%s()/%d write result to file fail!\n",
             "_ac_passthrough_response_get_from_one_ap",uVar4);
      uVar4 = 0xffffffff;
    }
  }
  return uVar4;
}

