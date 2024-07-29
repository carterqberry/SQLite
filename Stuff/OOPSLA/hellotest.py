import unittest
import hello

class HelloTestCase(unittest.TestCase):
    def testHello(self):
        assert hello.sayhello() == "Hello, world!"

if __name__ == "__main__":
    unittest.main()
