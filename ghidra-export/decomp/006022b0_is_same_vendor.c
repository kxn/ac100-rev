// func is_same_vendor @ 006022b0 size=24

bool is_same_vendor(uint param_1)

{
  return (param_1 & 0xff) == vendor_type;
}

