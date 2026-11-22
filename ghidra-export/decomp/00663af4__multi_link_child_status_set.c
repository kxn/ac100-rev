// func _multi_link_child_status_set @ 00663af4 size=108

undefined4 _multi_link_child_status_set(int param_1,ushort *param_2)

{
  if (((*(int *)(param_1 + 0x14) == 5) && ((int)*(short *)(param_1 + 0x18) == (uint)*param_2)) &&
     (*(int *)(param_1 + 0x2ac) - 2U < 2)) {
    _multi_link_status_switch(*(undefined2 *)(param_1 + 0x10),*(undefined1 *)(param_2 + 1),1,0,0,0);
  }
  return 0;
}

