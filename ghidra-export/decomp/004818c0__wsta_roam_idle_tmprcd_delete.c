// func _wsta_roam_idle_tmprcd_delete @ 004818c0 size=136

void _wsta_roam_idle_tmprcd_delete(int param_1,uint *param_2)

{
  uint uVar1;
  longlong lVar2;
  
  uVar1 = *param_2;
  if (param_1 != 0) {
    lVar2 = __udivdi3(*(undefined4 *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0x14),0,1000);
    if (((int)((ulonglong)(lVar2 + 10) >> 0x20) == 0) && ((uint)(lVar2 + 10) <= uVar1)) {
      FUN_00407f40(DAT_00767560,param_1);
      FUN_00407df0(param_1);
      return;
    }
  }
  return;
}

