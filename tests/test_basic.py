import RoadDataBase as RDB

def EasyCheck():
    rdb = RDB.RoadDB()
    a = RDB.Sign("a_", 0, RDB.Coordinate(1, 1))
    rdb.insert(a)

    b = rdb.find(0)

    assert a != None
    assert b != None
    assert a == b

def CheckLiveInterval():
    rdb = RDB.RoadDB()

    if True:
        a = RDB.Sign("a_", 12, RDB.Coordinate(2, 1))
        rdb.insert(a)

    b = rdb.find(12)

    assert b != None
    assert b.id == 12
    assert b.name == "a_"
    assert b.coordinate == RDB.Coordinate(2, 1)

def CheckCount():
    rdb = RDB.RoadDB()

    if True:
        a = RDB.Sign("a_", 11, RDB.Coordinate(2, 1))
        rdb.insert(a)
    
    b = RDB.Sign("a_", 12, RDB.Coordinate(2, 1))
    rdb.insert(b)

    assert rdb.find(11) != None
    assert rdb.find(12) != None
    # assert rdb.find(13) == None

def CheckErase():
    rdb = RDB.RoadDB()

    a = RDB.Sign("a_", 11, RDB.Coordinate(2, 1))
    rdb.insert(a)

    assert rdb.find(11) != None

    rdb.erase(11)
    assert rdb.find(11) == None

def CheckUniq():
    rdb = RDB.RoadDB()
    a = RDB.Sign("a_", 11, RDB.Coordinate(2, 1))
    
    rdb.insert(a)
    
    a_copy = rdb.find(a.id)

    a.name = "b_"

    assert a.name != a_copy.name
    assert a.coordinate == a_copy.coordinate

def AdvCheckErase():
    rdb = RDB.RoadDB()

    a = RDB.Sign("a_", 11, RDB.Coordinate(2, 1))
    rdb.insert(a);

    assert rdb.find(11) != None

    rdb.erase(11);
    assert rdb.find(11) == None

    assert a != None
    assert a.name == "a_"

tests=[
  EasyCheck,
  CheckLiveInterval,
  CheckCount,
  CheckErase,
  CheckUniq,
  AdvCheckErase
]

def test_main():
    for test in tests:
        test()

test_main()
