// func _wserv_entry_hash_obj @ 005ea208 size=108

undefined4 _wserv_entry_hash_obj(int param_1)

{
  size_t sVar1;
  undefined4 uVar2;
  
  if (param_1 != 0) {
    sVar1 = strlen((char *)(param_1 + 0x130));
    uVar2 = FUN_004083d0((char *)(param_1 + 0x130),sVar1,0);
    uVar2 = FUN_004083d0(param_1 + 300,4,uVar2);
    return uVar2;
  }
  return 0;
}

