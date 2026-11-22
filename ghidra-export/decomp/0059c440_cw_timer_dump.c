// func cw_timer_dump @ 0059c440 size=1

void cw_timer_dump(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (param_1 != (undefined4 *)0x0) {
    printf("-----------------capwap timer[%p]\'s info----------------------\r\n",param_1);
    iVar3 = 0;
    printf("max time: %d  max timer num: %d  current timer num: %d\r\n",param_1[1],*param_1,
           param_1[2]);
    for (iVar2 = 0; iVar2 < (int)param_1[1]; iVar2 = iVar2 + 1) {
      for (iVar1 = FUN_004081b0(param_1[4] + iVar2 * 0xc); iVar1 != 0; iVar1 = FUN_00408680(iVar1))
      {
        iVar3 = iVar3 + 1;
        printf("timer[%p]: timeout:[%llu] sec:%us\r\n",iVar1,*(undefined4 *)(iVar1 + 0x10),
               *(undefined4 *)(iVar1 + 0x14),*(undefined4 *)(iVar1 + 0x18));
      }
    }
    if (iVar3 == 0) {
      puts("empty timer\r");
    }
    (*(code *)PTR_puts_00758f90)
              ("----------------------------------------------------------------------\r");
    return;
  }
  if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
    printf("[CW_ERROR]%32s():%4d The cw_timer is NULL\n","cw_timer_dump",0xea);
    return;
  }
  return;
}

