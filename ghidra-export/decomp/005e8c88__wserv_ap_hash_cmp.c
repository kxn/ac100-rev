// func _wserv_ap_hash_cmp @ 005e8c88 size=40

bool _wserv_ap_hash_cmp(int *param_1,int *param_2)

{
  bool bVar1;
  
  bVar1 = false;
  if ((param_1 != (int *)0x0) && (param_2 != (int *)0x0)) {
    bVar1 = *param_1 == *param_2;
  }
  return bVar1;
}

