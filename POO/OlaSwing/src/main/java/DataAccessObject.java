import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.List;

public abstract class DataAccessObject<T> {

    public abstract List<T> findAll();
    //public abstract T findById(String id);
    public abstract T insert(T obj);
    //public abstract boolean update(T obj);
    //public abstract boolean delete(T obj);



    protected int getInsertedId(PreparedStatement ps) throws SQLException {
        Integer insertedId = null;
        ResultSet rs = ps.getGeneratedKeys();
        if (rs.next()) {
            insertedId = rs.getInt(1);
        }
        return insertedId;
    }



}
