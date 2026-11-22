// func FUN_00486664 @ 00486664 size=100

void FUN_00486664(undefined4 *param_1,int param_2,uint param_3)

{
  if ((param_1 != (undefined4 *)0x0) && (param_2 != 0)) {
    if (param_3 == 1) {
      _rssi_sort_fun(*param_1,*param_1,param_2);
      return;
    }
    if (1 < param_3) {
      _quick_sort_impl(param_1,param_2,0,param_3 - 1,_rssi_sort_fun);
    }
  }
  return;
}

