// func _apdb_unsupport_obj_hash_func @ 0060eca4 size=64

void _apdb_unsupport_obj_hash_func(char *param_1)

{
  size_t sVar1;
  undefined4 uVar2;
  
  sVar1 = strlen(param_1);
  uVar2 = FUN_004083d0(param_1,sVar1,0);
  FUN_004083d0(param_1 + 0x42,4,uVar2);
  return;
}

