// func _aut_sort_func @ 0042c88c size=92

void _aut_sort_func(int param_1,int param_2)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0xc) == 0) {
    if ((*(uint *)(param_1 + 0x10) & 0xffff0000) == 0) goto LAB_0042c8dc;
    iVar1 = *(int *)(param_2 + 0xc);
  }
  else {
    iVar1 = *(int *)(param_2 + 0xc);
  }
  if ((iVar1 != 0) || ((*(uint *)(param_2 + 0x10) & 0xffff0000) != 0)) {
    memcmp((void *)(param_1 + 0xc),(void *)(param_2 + 0xc),6);
    return;
  }
LAB_0042c8dc:
  strncmp((char *)(param_1 + 0x58),(char *)(param_2 + 0x58),0x28);
  return;
}

