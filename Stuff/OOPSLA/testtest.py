# Examine setUp and tearDown

import unittest

class TestTestCase(unittest.TestCase):
    def setUp(self):
        print "setting up"
    def tearDown(self):
        print "tearing down"
    def testA(self):
        assert True
    def testB(self):
        assert True

# Run all test methods (Disables individual tests below)
unittest.main()

print

# Run individually
test = TestTestCase("testA")
runner = unittest.TextTestRunner()
runner.run(test)
test = TestTestCase("testB")
runner.run(test)

