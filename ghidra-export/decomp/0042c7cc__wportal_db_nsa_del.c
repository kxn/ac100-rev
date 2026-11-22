// func _wportal_db_nsa_del @ 0042c7cc size=132

int _wportal_db_nsa_del(void *param_1)

{
  int iVar1;
  undefined1 auStack_2e0 [360];
  undefined1 auStack_178 [116];
  undefined1 auStack_104 [248];
  
  iVar1 = _wportal_db_nsa_get(param_1,auStack_2e0);
  if (iVar1 == 0) {
    memset(auStack_178,0,0x168);
    memcpy(auStack_104,param_1,6);
    FUN_00408690(nsa_tree,auStack_178);
    if (0 < nsa_count) {
      nsa_count = nsa_count + -1;
    }
  }
  return iVar1;
}

