def main():
    address = input()
    if '.' in address:
        address = list(map(int,address.split('.')))
        result = str()
        for x in reversed(address):
            if x > 255 or x < 0:
                print("INVALID")
                return
            result += str(str(x)+'.')
        result = str(result+"in-addr.arpa.")
    else:
        if "::" in address:
            colon_count = address.count(':')
            if colon_count < 7:
                insert_pos = address.find("::")
                address = list(address)
                for _ in range(7-colon_count):
                    address.insert(insert_pos,':')
            address = ''.join(address)
        
        result = str()
        count = 0
        for x in reversed(address):
            if x == ':':
                for _ in range(4-count):
                    result += '0.'
                count = 0
            else:
                result += str(x) + '.'
                count += 1
        if count < 4:
            for _ in range(4-count):
                result += '0.'
            count = 0
        result = str(result+"ip6.arpa.")
    return result



if __name__ == "__main__":
    result = main()
    print(result)



#---TESTS---------TESTS-------TESTS-----

import pytest

def test_case_1(monkeypatch):
    inputs = iter(["127.0.0.1"])
    monkeypatch.setattr('builtins.input', lambda: next(inputs))
    results = main()
    assert results == "1.0.0.127.in-addr.arpa."

def test_case_2(monkeypatch):
    inputs = iter(["2001:db8:0:0:0:ff00:42:8329"])
    monkeypatch.setattr('builtins.input', lambda: next(inputs))
    results = main()
    assert results == "9.2.3.8.2.4.0.0.0.0.f.f.0.0.0.0.0.0.0.0.0.0.0.0.8.b.d.0.1.0.0.2.ip6.arpa."

def test_case_3(monkeypatch):
    inputs = iter(["::1"])
    monkeypatch.setattr('builtins.input', lambda: next(inputs))
    results = main()
    assert results == "1.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.ip6.arpa."