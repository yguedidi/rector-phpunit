<?php

namespace Rector\PHPUnit\Tests\Rector\ClassMethod\ExceptionAnnotationRector\Fixture;

use PHPUnit\Framework\TestCase;

class Fixture5Test extends TestCase
{
    /**
     * @expectedException \Exception
     * @expectedExceptionMessage Message referencing a method, SomeClass::someMethod
     */
    public function testLiteralMessage(): void
    {
        throw new \Exception('Message referencing a method, SomeClass::someMethod');
    }
}

?>
-----
<?php

namespace Rector\PHPUnit\Tests\Rector\ClassMethod\ExceptionAnnotationRector\Fixture;

use PHPUnit\Framework\TestCase;

class Fixture5Test extends TestCase
{
    public function testLiteralMessage(): void
    {
        $this->expectException(\Exception::class);
        $this->expectExceptionMessage('Message referencing a method, SomeClass::someMethod');
        throw new \Exception('Message referencing a method, SomeClass::someMethod');
    }
}

?>
