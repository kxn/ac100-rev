// func _cloud_mngt_role_match @ 0048ba90 size=60

bool _cloud_mngt_role_match(uint param_1)

{
  bool bVar1;
  
  bVar1 = true;
  if ((((1 < param_1) && (param_1 != 3)) && (param_1 != 2)) && ((param_1 != 4 && (param_1 != 8)))) {
    bVar1 = param_1 == 6;
  }
  return bVar1;
}

