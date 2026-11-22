// func _wserv_entry_hash_cmp_func @ 005eb038 size=104

bool _wserv_entry_hash_cmp_func(int param_1,int *param_2)

{
  int iVar1;
  bool bVar2;
  
  bVar2 = false;
  if ((param_1 != 0) && (param_2 != (int *)0x0)) {
    iVar1 = strcmp((char *)(param_1 + 0x130),(char *)(param_2 + 1));
    bVar2 = false;
    if (iVar1 == 0) {
      bVar2 = *(int *)(param_1 + 300) == *param_2;
    }
  }
  return bVar2;
}

