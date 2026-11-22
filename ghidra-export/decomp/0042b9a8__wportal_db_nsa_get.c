// func _wportal_db_nsa_get @ 0042b9a8 size=120

undefined4 _wportal_db_nsa_get(void *param_1,void *param_2)

{
  void *__src;
  undefined4 uVar1;
  undefined1 auStack_178 [116];
  undefined1 auStack_104 [248];
  
  memset(auStack_178,0,0x168);
  memcpy(auStack_104,param_1,6);
  __src = (void *)FUN_004080c0(nsa_tree,auStack_178);
  uVar1 = 0xffffffff;
  if (__src != (void *)0x0) {
    memcpy(param_2,__src,0x168);
    uVar1 = 0;
  }
  return uVar1;
}

