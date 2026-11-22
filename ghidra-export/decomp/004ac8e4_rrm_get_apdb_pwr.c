// func rrm_get_apdb_pwr @ 004ac8e4 size=164

undefined4 rrm_get_apdb_pwr(int param_1,undefined1 *param_2,undefined1 *param_3,int param_4)

{
  undefined1 uVar1;
  undefined4 uVar2;
  
  if (((param_1 == 0) || (param_2 == (undefined1 *)0x0)) || (param_3 == (undefined1 *)0x0)) {
    uVar2 = 0xffffffff;
    if (rrm_err_switch != '\0') {
      printf("[RRM_ERROR]%s()/%d wrong input\n","rrm_get_apdb_pwr",0x532);
    }
  }
  else {
    if (param_4 == 0) {
      *param_2 = (char)*(undefined2 *)(param_1 + 0x20);
      uVar1 = (undefined1)*(undefined2 *)(param_1 + 0x22);
    }
    else {
      uVar1 = (undefined1)*(short *)(param_1 + 0x26);
      if (*(short *)(param_1 + 0x26) == 0) {
        uVar1 = *(undefined1 *)(param_1 + 0x21);
      }
      *param_2 = uVar1;
      if (*(short *)(param_1 + 0x28) == 0) {
        uVar1 = *(undefined1 *)(param_1 + 0x23);
      }
      else {
        uVar1 = (undefined1)*(short *)(param_1 + 0x28);
      }
    }
    uVar2 = 0;
    *param_3 = uVar1;
  }
  return uVar2;
}

