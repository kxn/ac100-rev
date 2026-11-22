// func cw_timer_remove @ 0059c230 size=208

undefined4 cw_timer_remove(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((param_1 == 0) || (param_2 == 0)) {
    uVar2 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[CW_ERROR]%32s():%4d The cw_timer or timer node is NULL\n","cw_timer_remove",0xaa);
    }
  }
  else {
    uVar2 = 0;
    if (*(int *)(param_2 + 0x28) == 0) {
      FUN_00408500(param_2);
      if (*(code **)(param_2 + 0x20) != (code *)0x0) {
        (**(code **)(param_2 + 0x20))(*(undefined4 *)(param_2 + 0x24));
      }
      *(undefined4 *)(param_2 + 0x28) = 1;
      uVar2 = 0;
      FUN_00407df0(param_2);
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -1;
    }
  }
  return uVar2;
}

