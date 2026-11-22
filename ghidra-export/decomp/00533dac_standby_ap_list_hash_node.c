// func standby_ap_list_hash_node @ 00533dac size=216

void standby_ap_list_hash_node(void *param_1,int param_2)

{
  uint uVar1;
  void *__s;
  uint uVar2;
  
  if ((param_1 != (void *)0x0) && (param_2 != 0)) {
    uVar1 = *(uint *)((int)param_1 + 0xc) + 0xf5;
    uVar2 = (uint)(uVar1 < *(uint *)((int)param_1 + 0xc)) + *(int *)((int)param_1 + 8);
    if (((uVar2 < *(uint *)(param_2 + 0x10)) ||
        ((*(uint *)(param_2 + 0x10) == uVar2 && (uVar1 < *(uint *)(param_2 + 0x14))))) &&
       (__s = (void *)FUN_00408450(0x18,0x1130), __s != (void *)0x0)) {
      memset(__s,0,0x18);
      memcpy((void *)((int)__s + 0xc),param_1,6);
      *(void **)((int)__s + 0x14) = param_1;
      *(undefined2 *)((int)__s + 0x12) = *(undefined2 *)((int)param_1 + 6);
      FUN_00408240(param_2,__s);
      return;
    }
  }
  return;
}

