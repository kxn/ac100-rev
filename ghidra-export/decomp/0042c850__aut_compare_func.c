// func _aut_compare_func @ 0042c850 size=60

void _aut_compare_func(int param_1,int param_2)

{
  if ((*(int *)(param_1 + 0xc) == 0) && ((*(uint *)(param_1 + 0x10) & 0xffff0000) == 0)) {
    strncmp((char *)(param_1 + 0x58),(char *)(param_2 + 0x58),0x28);
    return;
  }
  memcmp((void *)(param_1 + 0xc),(void *)(param_2 + 0xc),6);
  return;
}

