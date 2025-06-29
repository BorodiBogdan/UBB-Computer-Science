package Model.ADT;

import Model.Exceptions.DictionaryException;

import java.util.Map;

public interface IDictionary<K, V> {
    void addKeyValuePair(K newKey, V newValue);
    V lookUp(K key) throws DictionaryException;
    V removeByKey(K key) throws DictionaryException;
    boolean isDefined(K key);
    Map<K, V> getContent();
}
