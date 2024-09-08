// 0x030151C8
static const s16 door_seg3_animvalue_030151C8[] = {
    0x0000, 0xFED4,
};

// 0x030151CC
static const u16 door_seg3_animindex_030151CC[] = {
    0x0001, 0x0001, 0x0001, 0x0000, 0x0001, 0x0000, 0x0001, 0x0000, 0x0001, 0x0000, 0x0001, 0x0000,
    0x0001, 0x0000, 0x0001, 0x0000, 0x0001, 0x0000,
    0x0001, 0x0000, 0x0001, 0x0000, 0x0001, 0x0000,
    0x0001, 0x0000, 0x0001, 0x0000, 0x0001, 0x0000,
};

// 0x03015208
static const struct Animation door_seg3_anim_03015208 = {
    0,
    0,
    0,
    0,
    0x50,
    ANIMINDEX_NUMPARTS(door_seg3_animindex_030151CC),
    door_seg3_animvalue_030151C8,
    door_seg3_animindex_030151CC,
    0,
    ANIM_FIELD_LENGTH(door_seg3_animvalue_030151C8),
    ANIM_FIELD_LENGTH(door_seg3_animindex_030151CC),
};
